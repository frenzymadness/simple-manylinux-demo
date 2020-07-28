#!/bin/bash
set -e -u -x

function repair_wheel {
    wheel="$1"
    if ! auditwheel show "$wheel"; then
        echo "Skipping non-platform wheel $wheel"
    else
        auditwheel repair "$wheel" --plat "$PLAT" -w /io/wheelhouse/$PLAT
    fi
}

# Compile wheels
for PYBIN in /opt/python/*/bin; do
    "${PYBIN}/pip" wheel /io/ --no-deps -w /io/wheelhouse/$PLAT
done

# Bundle external shared libraries into the wheels
for whl in /io/wheelhouse/$PLAT/*.whl; do
    repair_wheel "$whl"
done

# Install packages and test
for PYBIN in /opt/python/*/bin/; do
    "${PYBIN}/pip" install simple-manylinux-demo --no-index -f /io/wheelhouse/$PLAT
    (cd "$HOME"; "${PYBIN}/python" -m unittest discover dummyextension.tests)
done
