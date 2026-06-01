from conan import ConanFile

class MypkgProject(ConanFile):
    name = "mypkg"
    version = "0.1"

    support_sdk_version = "^2.4"
    package_type = "application"

    requires = (
        # "core-lib/1.0.0",
        'self-balance-scooter/[^0.0.2]@nuoning',
    )

    generators = (
        "SConsDeps",
        "KconfigDeps",
    )
