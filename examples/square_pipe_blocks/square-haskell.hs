--
-- Compile with:
--   ghc -O2 --make square-haskell.hs
-- Then execute with:
--   ./square-haskell
--
-- Or, run with interpreter (slower than compiled version) with:
--   runhaskell ./square-haskell.hs
--

module Main where

import qualified Data.ByteString.Lazy as BL
import Data.Binary.Get
import Data.Binary.Put

import Data.ByteString.Lazy(toChunks,ByteString)
import Data.Binary.Get(pushChunk,Decoder(..),runGetIncremental)
import Data.List(unfoldr)

runGets :: Get a -> ByteString -> [a]
runGets g = unfoldr (decode1 d) . toChunks
  where d = runGetIncremental g

decode1 _ [] = Nothing
decode1 d (x:xs) = case d `pushChunk` x of
                     Fail _ _ str  -> error str
                     Done x' _ a   -> Just (a,x':xs)
                     k@(Partial _) -> decode1 k xs

square x = x * x

main :: IO ()
main = do
  contents <- BL.getContents
  let inVals = runGets getFloathost contents
  let outVals = [ square x | x <- inVals ]
  let outStr = [ runPut $ putFloathost val | val <- outVals ]
  BL.putStr $ BL.concat outStr
