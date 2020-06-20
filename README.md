# regime_cpp
[![the-new-bash](https://circleci.com/gh/the-new-bash/regime_cpp.svg?style=shield&circle-token=67c684a2743ce81c93b94d5f99829ec8a48bf5b6)](https://app.circleci.com/pipelines/github/the-new-bash/regime_cpp)
[![SonarCloud Coverage](https://sonarcloud.io/api/project_badges/measure?project=the-new-bash_regime_cpp&metric=coverage)](https://sonarcloud.io/component_measures/metric/coverage/list?id=the-new-bash_regime_cpp)

Australian Open Banking API C++17 client.

## Getting Started

### Dependencies
- [conan](https://conan.io/) (>= 1.22.2)
- cmake, make
- gcc

```bash
# Debian
apt-get -y update && apt-get -y install git g++ make cmake libssel-dev python3-pip python3-dev
pip3 install conan

# RedHat
yum install -y git gcc-c++ make cmake3 openssl-devel python36 python36-pip
pip3 install conan

# macOS
brew install cmake openssl python3
pip3 install conan
```

## Installation
```bash
git clone https://github.com/the-new-bash/regime_cpp.git && cd regime_cpp
conan create . <user>/<channel> --build=missing
```

## Usage
```python
# conanfile.py
class Consumer(ConanFile):
    requires = "regime/<version>@<user>/<channel>"
    ...
```
```c++
// main.cpp
#include "regime.hpp"

int main()
{    
    RegimeClient client(1);
    auto products = client.get_products(Bank::ANZ);
    auto details = client.get_product_details(Bank::ANZ, products[0].product_id);
}
```
