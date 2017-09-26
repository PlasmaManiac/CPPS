{-
 - @EXPECTED_RESULTS@: CORRECT
 -}
module Main where

import Control.Arrow
import Data.Array

main = interact (lines >>> tail >>> map testcase >>> unlines)

testcase = testcase' (listArray ('A','Z') [0,0..]) where
    testcase' f []
        = "OK"
    testcase' f [m1]
        | (f ! m1 + 1) `mod` 3 == 0 = "FAKE"
        | otherwise                 = "OK"
    testcase' f (m1:m2:ms)
        | (f ! m1 + 1) `mod` 3 /= 0
            = testcase' (f // [(m1, f ! m1 + 1)]) (m2:ms)
        | (f ! m1 + 1) `mod` 3 == 0, m1 == m2
            = testcase' (f // [(m1, f ! m1 + 1)]) ms
        | otherwise                  
            = "FAKE"
