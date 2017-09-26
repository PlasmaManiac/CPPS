{-
 - @EXPECTED_RESULTS@: CORRECT
 -}
module Main where

import Control.Arrow
import Data.List

main :: IO ()
main = interact $ lines >>> tail
                        >>> map (read >>> testcase >>> map show >>> unwords)
                        >>> unlines

testcase :: Int -> [Int]
testcase = factor >>> map (second pot) >>> concatMap (\(p,ks) -> map (p^) ks) >>> sort

factor :: Int -> [(Int,Int)]
factor = factor' (2:[3,5..]) where
    factor' _      1 = []
    factor' (p:ps) n
        | p * p > n = [(n,1)]
        | (q, 0) <- n `divMod` p = 
            case factor' (p:ps) q of
                []        -> (p, 1) : factor' (p:ps) q
                (p',k):fs | p == p'   -> (p,k+1)          : fs
                          | otherwise -> (p,  1) : (p',k) : fs
        | otherwise = factor' ps n
                           
pot :: Int -> [Int]
pot = pot' 1 where
    pot' k 1 = [k]
    pot' k n | n `mod` 2 == 0 =     pot' (2*k) (n `div` 2)
             | otherwise      = k : pot' (2*k) (n `div` 2)
