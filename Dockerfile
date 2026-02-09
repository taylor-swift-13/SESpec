FROM ubuntu:22.04

LABEL maintainer="SESpec"
LABEL description="SEComments - ACSL comments generation toolkit with LLVM-18"

ENV DEBIAN_FRONTEND=noninteractive
ENV PYTHONUNBUFFERED=1
ENV LLVM_CONFIG=/usr/bin/llvm-config-18
ENV CC=clang-18
ENV CXX=clang++-18

WORKDIR /home/yangfp/SESpec

RUN sed -i 's|http://archive.ubuntu.com|http://mirrors.tuna.tsinghua.edu.cn/ubuntu|g' /etc/apt/sources.list 2>/dev/null || true
RUN sed -i 's|http://security.ubuntu.com|http://mirrors.tuna.tsinghua.edu.cn/ubuntu|g' /etc/apt/sources.list 2>/dev/null || true

RUN apt-get update && apt-get install -y --no-install-recommends \
    wget \
    gnupg \
    lsb-release \
    software-properties-common \
    curl \
    ca-certificates

RUN apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 15CF4D18AF4F7421 2>/dev/null || \
    (wget -qO- https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add -) || true

RUN echo "deb http://apt.llvm.org/jammy/ llvm-toolchain-jammy-18 main" > /etc/apt/sources.list.d/llvm-18.list

RUN apt-get update && apt-get install -y --no-install-recommends \
    clang-18 \
    llvm-18-dev \
    llvm-18-tools \
    libz3-dev \
    python3.10 \
    python3.10-dev \
    python3-pip \
    python3-venv \
    libpython3.10 \
    build-essential \
    cmake \
    git \
    vim \
    && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/clang clang /usr/bin/clang-18 100 && \
    update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-18 100 && \
    update-alternatives --install /usr/bin/llvm-config llvm-config /usr/bin/llvm-config-18 100

COPY requirements.txt .

RUN pip install --no-cache-dir --upgrade pip wheel && \
    pip install --no-cache-dir -r requirements.txt

COPY . .

RUN chmod +x run.sh

VOLUME ["/home/yangfp/SESpec/models", "/home/yangfp/SESpec/data"]

ENV MODEL_PATH=/home/yangfp/SESpec/models
ENV DATA_PATH=/home/yangfp/SESpec/data

CMD ["bash"]
