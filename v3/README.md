# v3new

本项目最初基于上传压缩包中的 **v3/main.tex 和 v3/chapters/** 重组。
现在以 **diff.tex 和 diff_chapters/** 为唯一内容来源，其他三个版本由其生成。
原压缩包顶层的 v1、v2 未作修改，也未复制进本项目。v3 原有的图片、
参考文献数据库、IEEE 模板、审稿记录和 history 文件保持不变。

## 四套 LaTeX

| 入口文件 | 对应章节目录 | 内容 | 本次编译页数 |
| --- | --- | --- | --- |
| `diff.tex` | `diff_chapters/` | 当前 v3 的完整正文和附录，保留修订标记 | 27 |
| `whole.tex` | `whole_chapters/` | 与 diff 内容一致的完整版，无修订标记 | 27 |
| `main.tex` | `chapters/` | 从 whole 拆出的正文及完整参考文献 | 14 |
| `appendix.tex` | `appendix_chapters/` | 从新 whole 拆出的附录 A–L | 13 |

四个入口都可直接使用 pdfLaTeX 编译，不需要通过命令行定义版本开关。
导入项目后，将需要编译的入口设为主文件即可。对应的四份 PDF 已随项目附上。

## 修改范围

同步过程保持 `diff.tex` 和 `diff_chapters/` 原样，不改写论文内容。
干净版移除 `\rev{...}`、`\yfp{...}`、`\wsl{...}` 的标记及修订颜色。
**只移除修订标记，
不删除其中的文字、公式或其他内容。** 必要的 LaTeX 分组花括号保留，以免
其中的字号或格式声明影响后文。图表和代码示例原有的配色不属于修订标记，
因此保持原样。

## 拆分后的引用

main 中的附录引用保留“in the supplementary material”的说明。
appendix 中的图、表、算法等编号与 whole 一致，页码从 1 重新开始。
main 的参考文献中保留了附录引用的文献，所以两份文件共享同一套文献编号；
appendix 不重复排版参考文献，其文献链接及正文交叉引用指向 `main.pdf`。
跨 PDF 跳转的具体支持取决于所用 PDF 阅读器。

`references/` 内的 `.tex` 文件保存了必要的标签、引用编号和计数器快照，
因此只编译 main 或 appendix 也不依赖临时 `.aux` 文件，不需要先在
Overleaf 编译 whole。不要删除 `references/`。

## 本地重新构建

需要 pdfLaTeX、BibTeX、Python 3，以及原项目使用的 LaTeX 宏包：

```bash
bash build_pdfs.sh
```

该脚本先运行 `support/sync_from_diff.py`，从 diff 生成其他三个入口及对应
章节，并按附录中的引用顺序更新 `references/appendix_nocite.tex`。
随后编译 whole，刷新正文/附录之间的标签、计数器和文献编号，生成四份 PDF。
今后请在 diff 中修改内容；构建时会覆盖其他三个版本中偏离 diff 的修改。

仅同步源文件或检查是否同步，可分别运行：

```bash
python3 support/sync_from_diff.py
python3 support/sync_from_diff.py --check
```

生成后的四个入口仍可独立编译；直接使用 pdfLaTeX 或上传 Overleaf 时，
不需要运行 Python。修改 diff 后应先在本地同步并重新构建，再上传更新文件。

## 本次检查

2026-10-18：以当前 diff 为唯一内容来源完成同步与四版重编译。

四套文件均已实际编译。最终日志没有未定义的引用、未定义的文献或重复标签，
PDF 中未发现 `??` 占位符。三个干净版本的源文件已按 diff 同步，
`support/sync_from_diff.py --check` 可检查是否再次出现内容偏差。

原模板仍有字号替代和未使用的 `lettersize` 选项警告；附录排版可能出现
约 9.8pt 的 `Overfull \vbox` 警告。页数随内容排版变化，不作为固定约束。
