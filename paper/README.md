# v3new

本项目只基于上传压缩包中的 **v3/main.tex 和 v3/chapters/** 重组。
原压缩包顶层的 v1、v2 未作修改，也未复制进本项目。v3 原有的图片、
参考文献数据库、IEEE 模板、审稿记录和 history 文件保持不变。

## 四套 LaTeX

| 入口文件 | 对应章节目录 | 内容 | 本次编译页数 |
| --- | --- | --- | --- |
| `diff.tex` | `diff_chapters/` | 当前 v3 的完整正文和附录，原修订标记改为蓝色 | 26 |
| `whole.tex` | `whole_chapters/` | 完整正文和附录，无修订标记 | 26 |
| `main.tex` | `chapters/` | 从新 whole 拆出的正文及完整参考文献 | 14 |
| `appendix.tex` | `appendix_chapters/` | 从新 whole 拆出的附录 A–K | 12 |

四个入口都可直接使用 pdfLaTeX 编译，不需要通过命令行定义版本开关。
导入项目后，将需要编译的入口设为主文件即可。对应的四份 PDF 已随项目附上。

## 修改范围

旧 `diff.tex` 和旧 `diff_chapters/` 已被当前 main 内容替换，不再保留旧的
latexdiff 内容。diff 中的修订文字以及使用修订色的图中文字均显示为蓝色。

干净版共移除了原文件中的 172 处 `\rev{...}` 标记。**只移除修订标记，
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

该脚本先编译 whole，再刷新正文/附录之间的标签、计数器和文献编号，
最后生成四份 PDF。四套章节文件互相独立；今后修改内容时，需要同步修改
希望保持一致的版本。若增加了仅在附录出现的文献，也需更新
`references/appendix_nocite.tex` 中相应的引用键。

## 本次检查

四套文件均已实际编译。最终日志没有未定义的引用、未定义的文献或重复标签，
PDF 中未发现 `??` 占位符。diff 与 whole 均为 26 页，但两套章节文件仍有
早于本次文字修改的内容差异，不能视为逐页文本相同。

原模板的字号替代、未使用的 `lettersize` 选项和一处约 6pt 的浮动页
`Overfull \vbox` 警告仍存在；这些同样出现在原始 main 的基准编译中。
已检查渲染页面，未对原有排版作额外修改。
