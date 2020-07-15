#parse("FILE_HEAD_PY.py")
#parse("LICENSE_MIT_PY.py")
import unittest

class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(True, False)

if __name__ == '__main__':
    unittest.main()
