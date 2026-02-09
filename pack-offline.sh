#!/bin/bash

echo "=========================================="
echo "  SESpec Docker 离线打包工具"
echo "=========================================="
echo ""
echo "使用方法:"
echo "  1. 在有网络的机器上运行: ./pack-offline.sh"
echo "  2. 这将生成 sespec-offline.tar"
echo "  3. 拷贝 sespec-offline.tar 到离线机器"
echo "  4. 在离线机器上运行: docker load -i sespec-offline.tar"
echo "  5. 运行: docker run -it sespec:offline bash"
echo ""

IMAGE_NAME="sespec-offline"
OUTPUT_FILE="sespec-offline.tar"

if [ ! -f "Dockerfile" ]; then
    echo "错误: 未找到 Dockerfile"
    exit 1
fi

if [ ! -f "requirements.txt" ]; then
    echo "错误: 未找到 requirements.txt"
    exit 1
fi

echo "步骤 1: 构建镜像..."
docker build -t $IMAGE_NAME:build . 2>&1 | tail -10

if [ $? -ne 0 ]; then
    echo "构建失败，请检查网络连接"
    exit 1
fi

echo ""
echo "步骤 2: 标记最终镜像..."
docker tag $IMAGE_NAME:build $IMAGE_NAME:offline

echo ""
echo "步骤 3: 导出为离线包..."
docker save $IMAGE_NAME:offline -o $OUTPUT_FILE

echo ""
echo "=========================================="
echo "  完成!"
echo "=========================================="
echo ""
echo "离线包: $OUTPUT_FILE ($(du -h $OUTPUT_FILE | cut -f1)"
echo ""
echo "在离线机器上:"
echo "  docker load -i $OUTPUT_FILE"
echo "  docker run -it $IMAGE_NAME:offline bash"
echo ""
echo "验证安装:"
echo "  docker run --rm $IMAGE_NAME:offline llvm-config-18 --version"
