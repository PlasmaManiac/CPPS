{-
 - @EXPECTED_RESULTS@: CORRECT
 -}
module Main where

import Prelude            hiding (lookup)
import Data.Char          (ord)
--import Data.IntMap.Strict (IntMap, empty, insert, lookup)
import Data.IntMap        (IntMap, empty, insert, lookup)
import Data.List          (sortBy)
import Control.Arrow

main = interact (lines >>> (\(n:ls) -> run (read n) ls) >>> unlines)
    where run 0 []           = []
          run n (_:k1:k2:m:ls) = decrypt k1 k2 m : run (n-1) ls

decrypt k1 k2 m =
    let im = foldr (\(i,w) -> insert (w2i w) i) empty (zip [0..] (words k1))
        cmp (w1, _) (w2, _) = compare (lookup (w2i w1) im) (lookup (w2i w2) im)
     in unwords . map snd $ sortBy cmp (zip (words k2) (words m))

w2i = foldr (\x r -> 26 * r + (ord x - ord 'A' + 1)) 0
