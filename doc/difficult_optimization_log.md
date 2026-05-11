# Difficult Bench Optimization Log

跟踪每一轮 prompt / example 改动 + 回归结果。约束：**不改代码**，只动 prompt 和 examples。模型 gpt-4o（temperature=0.2）。bench 路径 `src/input/Difficult/`，36 个 case。

---

## 1. Baseline（commit `056166d59`）

总通过 **10/36**：cases 1, 4, 6, 17, 18, 20, 27, 30, 35, 36

26 失败拆分：
- **14 infra-fail**（秒级挂，0 token，prompt/example 无法救）：10, 11, 12, 13, 14, 15, 19, 21, 22, 23, 24, 25, 28, 34
- **12 LLM-fail**（进了 LLM 但 spec 不收敛）：2, 3, 5, 7, 8, 9, 16, 26, 29, 31, 32, 33

---

## 2. 优化轮次

### Round 1 — 加 3 个 example
新增：
- `examples/numeric/parity_invariant.c` — nondeterministic 循环 + 奇偶 (x+y)%2 不变量
- `examples/numeric/sequential_loops.c` — 多 while 串行 + 共享累加器
- `examples/array/array_swap_permutation.c` — 数组就地置换 + `count_eq` logic + permutation invariant

回归：核心 4 组 4/4 ✅；Difficult **16, 31 新通过**。
**12/36**

### Round 2 — 强化 universal A6 hint
`prompt/error_hints/universal.txt` 的 A6 重写：
- 措辞硬化：「**NEVER** mention local in requires / ensures / assigns」
- 拆三段：assigns 允许什么、ensures 允许什么、不许编造名字
- 加 2 个 WRONG/RIGHT 对比

针对 5, 7, 8, 9, 26 反复出现的 `unbound logic variable <local>`。

回归：核心 LIG-MM/1 第 1 次失败（`unbound logic variable p`，再跑就过，sampling 抖动）；Difficult **5, 9, 29 新通过**。
**15/36**

### Round 3 — recursive_ds 强化
新增：
- `examples/recursive_ds/list_traverse_preserve.c` — 链表遍历 + 参数保持不变模式（`l == \at(l,Pre)` 风格不变量）

新增 `recursive_ds.txt` D5 hint：合约最小化、不必要时不发明 helper logic。

回归：**26, 32 新通过**；但 LIG-MM/1 第 2 次失败，原因是 D5 hint 里列了具体「坏名字」`length`/`lseg_length`，LLM 复读这些名字（**负例 backfire**）。
**17/36**

### Round 3.5 — D5 移除负例名字
`recursive_ds.txt:D5` 删除具体名字，改成抽象「helper 不在 logic 块里就 unbound」。
`list_traverse_preserve.c` 注释同步去掉这些名字。

回归：核心 4/4 ✅；Difficult **8 新通过**。
**18/36**

### Round 4 — decrement-chain example
新增：
- `examples/numeric/decrement_chain.c` — 生产-消费模式：第 1 个 while 累加 `k`，第 2 个 while `k--`，关键不变量 `k + j == n`

针对 case 3（`assert k>0` in consumer loop，需要 `k+j==total` 不变量）。
case 7 因 `create_general_template_file` 把 predicates 摆到 struct 前导致 forward reference，需改代码，本轮跳过。

回归：核心 LIG-MM/1 又失败（新错误 `symbol lseg is a predicate, not a function`，LLM 把 predicate 当函数用）；Difficult 无新通过，case 7/33 部分进展但未到 pass。
**18/36**

### Round 5 — predicate-as-function hint
新增 `recursive_ds.txt` D5a hint：
> `predicate` ≠ function returning value。不能在 `==` 右边、不能跟整数比较、不能当算术参数。错误信号 `symbol X is a predicate, not a function`。

回归：核心 LIG-MM/1 又失败（新错误 `unexpected token ''`）；Difficult **33 新通过**。
**19/36**

---

## 3. 阶段汇总

| 轮次 | 改动 | 新通过 | 总通过 |
|---|---|---|---|
| Baseline | — | — | 10/36 |
| R1 | +3 examples (parity, sequential_loops, array_swap) | 16, 31 | 12 |
| R2 | universal A6 强化 | 5, 9, 29 | 15 |
| R3 | recursive_ds list_traverse_preserve + D5 hint | 26, 32 | 17 |
| R3.5 | D5 去坏名字 | 8 | 18 |
| R4 | decrement_chain example | — | 18 |
| R5 | predicate-as-function hint (D5a) | 33 | **19** |

**净收益 +9 case**（10→19）。

---

## 4. 改动文件清单（git status 视图）

prompt 改动（已编辑现有文件）：
- `src/prompt/error_hints/universal.txt` — A6 重写（R2）
- `src/prompt/error_hints/recursive_ds.txt` — D5 + D5a（R3, R3.5, R5）

新增 example：
- `src/examples/numeric/parity_invariant.c`（R1）
- `src/examples/numeric/sequential_loops.c`（R1）
- `src/examples/numeric/decrement_chain.c`（R4）
- `src/examples/array/array_swap_permutation.c`（R1）
- `src/examples/recursive_ds/list_traverse_preserve.c`（R3，R3.5 改注释）

**未改代码**。所有改动都是 prompt 和 example，对所有 category 通用，不针对单个 case 硬编码。

---

## 5. 剩余 17 失败 — 详细诊断

### 5.1 LLM-fail 3 个（prompt/example 边际收益已耗尽）

| case | 函数 | 难点 |
|---|---|---|
| 2 | `foo65` | nested unknown-driven loop + 奇偶 parity；R1 加了 `parity_invariant.c` example 但内层 loop 嵌套打断 LLM 推理 |
| 3 | `foo0011` | 3 个串行 while，最后一个 `assert k>0` 需要跨循环传递 `k+j1==n0+n1` 不变量；R4 的 `decrement_chain.c` 已经是同模式但 LLM 仍未稳定推出 |
| 7 | `main23` (prepend_equal) | **不是 LLM 问题，是 code-level 结构 bug**：`create_general_template_file` 把 `/*@ predicate ... */` 放在 `struct SLL` 定义之前，导致 `Cannot find field tail in type struct SLL` 的 forward reference。改代码才能解锁。 |

case 2 / 3 继续加 example 收益越来越低，且会增加 prompt 长度对其它 case 造成 token / sampling 干扰。case 7 已经被定位为代码 bug。

### 5.2 infra-fail 14 个 — 按错误分 4 类

prompt 完全无法触达，必须改代码。

| 类型 | cases | 错误 | 根因 | 最小修复 |
|---|---|---|---|---|
| Python 递归深度溢出 | 10, 11, 12, 34 | `maximum recursion depth exceeded while calling a Python object` | 调用图遍历 / AST visitor 递归没有深度保护 | `sys.setrecursionlimit(N)` 兜底，或把递归改迭代 |
| 缺 `malloc` 函数注册 | 13, 15, 19, 25 | `Error: Can not Found Function 'malloc'` → `'NoneType' object has no attribute 'callee_set'` | libc 符号没在 FunctionInfo 表里，pending-function 流程拿到 `None` 后直接 NPE | 给 `malloc` / `calloc` / `free` 注册占位 FunctionInfo + 跳过它们的 callee 分析 |
| 缺 `__assert_fail` 函数注册 | 14, 21, 22, 23, 24 | `Error: Can not Found Function '__assert_fail'` → 同上 NPE | 同上，libc assert 宏展开成 `__assert_fail` 调用 | 给 `__assert_fail` 注册占位 FunctionInfo |
| 静默 0-token 退出 | 28 | `moo2` 进 LLM 前流程结束，`Total API calls: 0`，0.19s 完成 | 估计 `auto only_loop` / pending-function 状态机走到一个 no-op 出口（函数无 callee 时直接跳过 spec 生成） | 检查 `main.py` 入口分支，确保即使函数无 callee 也要生成 spec |

---

## 6. 发现的次级问题

### 6.1 LIG-MM/1 在 recursive_ds 大 prompt 上 sampling 不稳
5 轮里 3 次失败，**每次错误都不一样**：
- `unbound logic variable p`（local 漏写）
- `lseg_length unbound logic function`（编造 helper）
- `symbol lseg is a predicate, not a function`（混用 predicate / logic）
- `unexpected token ''`（parser 噪声）

不是单一 hint 缺失，是 gpt-4o 在 recursive_ds prompt 累计加长后随机翻车。**重跑通常能过**。每轮针对当前错误加 hint 后下一轮换新错误，呈打地鼠态势。

可能解：
- 降低 prompt 总量（合并重复 hints）
- 用更稳的 sampling（temp=0）—— 但 R1-R5 加 hint 的效果可能依赖采样多样性
- 多次采样取最佳（已有 best-tracking + rollback 兜底）

### 6.2 D5 hint 负例 backfire（R3 教训）
**列具体「坏名字」作反面例 → LLM 会复读这些名字**。
R3 hint 列了 `length` / `count` / `lseg_length`，LLM 立刻用它们生成 unbound helper。R3.5 改成抽象描述后才稳定。
**通用启示**：教 LLM「不要做 X」时，避免给出具体的 X 字符串；改用抽象规则描述。

### 6.3 examples 触达机制
- 通过 `get_examples_for(category)` 按 4 个 category 分别注入
- numeric / array / recursive_ds / recursive_program 互相独立，不交叉
- 加新 example 不会影响其它 category 的 prompt 长度 ✅
- 同一 category 内 example 越多 prompt 越长，需注意 token 成本

---

## 7. 总评

- **prompt/example 路径上限约 19/36**，继续加 hint 边际收益接近 0 且有 sampling 退化风险
- **真正卡点是 14 个 infra-fail**，全是代码层缺陷：libc stub 缺失 + 递归深度 + 状态机出口。解锁这些需要改 `main.py` / FunctionInfo 注册逻辑
- **case 7 也是代码层**：模板组装顺序错（predicate 放 struct 前）
- 单点收益最高的代码改动顺序建议：
  1. 给 `malloc` / `__assert_fail` 加占位 FunctionInfo（解锁 9 个 case：13-15, 19, 21-25）
  2. 加 `sys.setrecursionlimit` + 迭代化递归 traversal（解锁 4 个：10, 11, 12, 34）
  3. 修 `create_general_template_file` 摆放顺序（解锁 case 7）
  4. 修 `main.py` no-callee 出口（解锁 case 28）
- 全部修完上限约 **34/36**，剩下 2/3 是真 LLM 难题
