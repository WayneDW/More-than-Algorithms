#!/usr/bin/python
import unittest


class Solution(object):
    def isValidBST(self, root):
        if root: 
            return self.check(root, -10 ** 10, 10 ** 10)
        else:
            return True
   
    def check(self, root, Tmin, Tmax):
        leftValid, rightValid = True, True

        if Tmin >= root.val or root.val >= Tmax:
            return False
        if root.left:
            leftValid = self.check(root.left, Tmin, root.val)
        if root.right:
            rightValid = self.check(root.right, root.val, Tmax)

        return (leftValid and rightValid)



class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_method(self):
        """Such as self.assertEqual, self.assertTrue"""
        #self.assertEqual(self.s.)
        pass

def main():
    s = Solution()


if __name__ == "__main__":
    unittest.main()
