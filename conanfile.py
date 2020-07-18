from conans import ConanFile, CMake, tools


def git_get_semver():
    """Uses git to work out a semver compliant version tag"""
    git = tools.Git()
    try:
        # If not in a git repo this command will output error to stderr.
        # So we redirect the error message to /dev/null
        prev_tag = git.run("describe --tags --abbrev=0 2> /dev/null")
        commits_behind = int(git.run("rev-list --count %s..HEAD" % (prev_tag)))
        # Commented out checksum due to a potential bug when downloading from bintray
        # checksum = git.run("rev-parse --short HEAD")
        if prev_tag.startswith("v"):
            prev_tag = prev_tag[1:]
        if commits_behind > 0:
            prev_tag_split = prev_tag.split(".")
            prev_tag_split[-1] = str(int(prev_tag_split[-1]) + 1)
            output = "%s-%d" % (".".join(prev_tag_split), commits_behind)
        else:
            output = "%s" % (prev_tag)
        return output
    except:
        return '0.0.0'


class RegimeConan(ConanFile):
    name = "regime"
    version = git_get_semver()
    settings = "os", "compiler", "build_type", "arch"
    requires = "Poco/1.9.4@pocoproject/stable", "gtest/1.8.1@bincrafters/stable"
    generators = "cmake"
    exports_sources = "src/*", "include/*", "test/*", "CMakeLists.txt"
    default_options = {"Poco:enable_xml": False,
                       "Poco:enable_mongodb": False,
                       "Poco:enable_data": False,
                       "Poco:enable_data_sqlite": False,
                       "Poco:enable_zip": False,
                       "Poco:enable_redis": False}

    def build(self):
        cmake = CMake(self)
        cmake.verbose = True
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.hpp", dst="include", src="include", keep_path=True)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["regime"]
