# simple-manylinux-demo

This is a simplified version of [python-manylinux-demo](https://github.com/pypa/python-manylinux-demo) from [manylinux project](https://github.com/pypa/manylinux).

The purpose of this project is to create a simple package with CPython extension and build as many manylinux wheels from it as possible. The wheels are then used for testing support of installation on various architectures.

The wheels are published on [PyPI](https://pypi.org/project/simple-manylinux-demo) so you can use them and you don't have to build your own.

## Requirements

* podman or docker — to use manylinux container images for building wheels
* qemu-user-static — to build for different architectures (RPM/DEB package or [container images](https://github.com/multiarch/qemu-user-static))

## How to build them

To build all wheels for all platforms (see [platforms_list.txt](platforms_list.txt)) and all available Python versions just run `build-all.sh`.

If you are interested in one platform only, run:

```
PLAT=manylinux2014_x86_64
podman run --rm -e PLAT=$PLAT -v `pwd`:/io quay.io/pypa/manylinux$PLAT /io/build-wheels.sh
```

and the wheels appear in `./wheelhouse/$PLAT`.

## License

CC0 1.0
