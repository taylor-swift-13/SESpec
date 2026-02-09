# Docker 部署指南

## 快速开始

```bash
# 1. 配置环境变量
cp .env.example .env
# 编辑 .env 填入 API_KEY 等配置

# 2. 构建并运行
docker compose build
docker compose up -d
```

## 离线打包与部署

### 打包 (有网络机器)

```bash
chmod +x pack-offline.sh
./pack-offline.sh
# 生成: sespec-offline.tar
```

### 部署 (离线机器)

```bash
# 导入镜像
docker load -i sespec-offline.tar

# 运行容器
docker run -it --rm \
  -v $(pwd)/src:/home/yangfp/SESpec/src \
  -v $(pwd)/data:/home/yangfp/SESpec/data \
  -e API_KEY=your-key \
  sespec-offline bash
```

## 常用命令

| 命令 | 说明 |
|------|------|
| `docker compose build` | 构建镜像 |
| `docker compose up -d` | 后台运行 |
| `docker compose down` | 停止服务 |
| `docker exec -it sespec bash` | 进入容器 |
| `docker exec sespec llvm-config-18 --version` | 验证 LLVM |

## 验证

```bash
docker exec sespec llvm-config-18 --version
# 输出: 18.1.8
```

## 目录挂载

| 本地 | 容器内 |
|------|--------|
| `./src` | `/home/yangfp/SESpec/src` |
| `./data` | `/home/yangfp/SESpec/data` |
| `./models` | `/home/yangfp/SESpec/models` |

## 环境变量 (.env)

```bash
API_KEY=your-api-key
BASE_URL=https://api.example.com/v1
API_MODEL=Qwen3-72B
```
