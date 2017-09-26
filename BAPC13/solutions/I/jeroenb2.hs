{-
 - @EXPECTED_RESULTS@: CORRECT
 -}
import Data.List

main :: IO ()
main = interact $ unlines . map (unwords . map show . testcase . read) . tail . lines

testcase :: Integer -> [Integer]
testcase = sort . combine . factors

combine :: [Integer] -> [Integer]
combine (x:y:ys) | x == y    = combine (x * y : combine ys)
                 | otherwise = x : combine (y : ys)
combine ys = ys

factors :: Integer -> [Integer]
factors = f 2 where
  f p i | p * p > i     = [i] 
        | i `mod` p > 0 = f (p+1) i
        | otherwise     = p : f p (i `div` p)