{-
 - @EXPECTED_RESULTS@: CORRECT
 -}
import Data.Ratio
import Data.Maybe

main :: IO ()
main = interact $ unlines . testcases . map words . tail . lines

-- Lelijk invoer lezen
testcases :: [[String]] -> [String]
testcases [] = []
testcases ([n]:[noise]:plisten:xs) = ret : testcases ys where
  (mics,ys)       = splitAt (read n) xs
  readPos [x,y]   = (read x, read y)
  readMic [x,y,s] = (readPos [x,y], read s)
  ret = case testcase (read noise) (readPos plisten) (map readMic mics) of
    Just i  -> show i
    Nothing -> "NOISE"

-- De oplossing zelf
type Position = (Integer, Integer)

distsq :: Position -> Position -> Integer
distsq (x1,y1) (x2,y2) = (x1 - x2)^2 + (y1 - y2)^2

testcase :: Integer -> Position -> [(Position, Integer)] -> Maybe Integer
testcase noise plisten mics = listToMaybe $ catMaybes ret where
  rs :: [ Double ]
  rs = [ (fromInteger s) / (fromInteger $ distsq p plisten) | (p,s) <- mics]
  sumr :: Double
  sumr = sum rs
  ret :: [ Maybe Integer ]
  ret = [ if 7 * r > 6 * (fromInteger noise + sumr) then Just i else Nothing 
        | (r,i) <- zip rs [1..]]
