#!/bin/bash
# 加载 opam 环境

echo 'eval $(opam env)' >> ~/.bashrc
source ~/.bashrc
echo "✅ opam environment loaded successfully"
