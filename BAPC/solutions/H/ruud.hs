{-
 - @EXPECTED_RESULTS@: CORRECT
 -}
module Main where

main = interact (unlines . map show . run . tail . lines) where
    run []       = []
    run (s:n:ls) = let (is, ls') = splitAt (read n) ls
                    in testcase (read s) (map (map read . words) is) : run ls'

testcase s = (s+) . sum . map product
