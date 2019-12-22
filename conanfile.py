from conans import ConanFile, CMake


class RegimeConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "Poco/1.9.4@pocoproject/stable", "OpenSSL/latest_1.1.1x@conan/stable"
    ngenerators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
