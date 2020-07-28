from unittest import TestCase
from dummyextension.extension import hello


class TestExtension(TestCase):
    def test_hello(self):
        self.assertEqual(hello(), "Hello from Python extension!")
