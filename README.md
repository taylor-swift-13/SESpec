# SECOMMENTS

SEComments is a toolkit designed for end-to-end generation of ACSL comments for C programs. 

### Repository Structure
- `src/`: Main source for comments generation workflows
  - `input/`: input dictionary, input programs with manually annotated ACSL format preconditions and verification goals
  - `output/`: output dictionary, output programs with complete ACSL format comments
- `configs/`: Configuration files for the comment generation process
  - `func_config.json`: Default configuration file for function comments generation
  - `loop_config.yaml`: Configuration file for loop invariant generation

- `RESULTS/`: Raw experiment results
- `VST/`: Symbolic executor

### Requirements
- Linux (Ubuntu 22.04)
- Python 3.9+ (3.10/3.11 recommended)
- Frama-C (29.0 Copper)
- LLVM-config-18 (18.1.8)

### Setup 
##### Python Environment

```bash
conda env create -f environment.yml
conda activate SESpec
```

##### Openai-API Config

add your own api key and base url in `config.py`

```python
api_key:str = "your-key" 
base_url:str = "your-base-url" 
```

##### Verify

```bash
#run
llvm-config-18 --version
#see
18.1.8
```
```bash
#run
clang-18 --version
#see
Ubuntu clang version 18.1.8 (++20240731024944+3b5b5c1ec4a3-1~exp1~20240731145000.144)
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
```

```bash
#run
frama-c -v
#see
29.0 (Copper)
```

##### init opam

```bash
#run
cd src
bash init.sh
#see
opam environment loaded successfully
```

### Quick Start

```bash
#run
cd src
```

```bash
python main.py --config configs/air_config.yaml --function foo
```

