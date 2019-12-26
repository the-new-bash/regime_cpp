from conans import ConanFile, CMake


class RegimeConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "Poco/1.9.4@pocoproject/stable"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
