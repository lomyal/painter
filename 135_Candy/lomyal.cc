
// 1、自己的解法，空间高
// T=O(n)
// S=O(n)

class Solution {
public:
    int candy(vector<int> &ratings)
    {
        int size = (int)ratings.size();
        vector<int> candyInHand(size, 1);

        for (int i = 1; i < size; i++) {
            if (ratings[i - 1] < ratings[i]) {
                candyInHand[i] = candyInHand[i - 1] + 1;
            }
        }

        for (int i = size - 1; i > 0; i--) {
            if (ratings[i] < ratings[i - 1] && candyInHand[i] + 1 > candyInHand[i - 1]) {
                candyInHand[i - 1] = candyInHand[i] + 1;
            }
        }

        int sum = 0;
        for (auto n : candyInHand) {
            sum += n;
        }

        return sum;
    }
};

// 2、
// T=O(n)
// S=O(1)

int candy(vector<int> &ratings) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    int nCandyCnt = 0;///Total candies
    int nSeqLen = 0;  /// Continuous ratings descending sequence length
    int nPreCanCnt = 1; /// Previous child's candy count
    int nMaxCntInSeq = nPreCanCnt;
    if(ratings.begin() != ratings.end())
    {
        nCandyCnt++;//Counting the first child's candy.
        for(vector<int>::iterator i = ratings.begin()+1; i!= ratings.end(); i++)
        {
            // if r[k]>r[k+1]>r[k+2]...>r[k+n],r[k+n]<=r[k+n+1],
            // r[i] needs n-(i-k)+(Pre's) candies(k<i<k+n)
            // But if possible, we can allocate one candy to the child,
            // and with the sequence extends, add the child's candy by one
            // until the child's candy reaches that of the prev's.
            // Then increase the pre's candy as well.

            // if r[k] < r[k+1], r[k+1] needs one more candy than r[k]
            //
            if(*i < *(i-1))
            {
                //Now we are in a sequence
                nSeqLen++;
                if(nMaxCntInSeq == nSeqLen)
                {
                    //The first child in the sequence has the same candy as the prev
                    //The prev should be included in the sequence.
                    nSeqLen++;
                }
                nCandyCnt+= nSeqLen;
                nPreCanCnt = 1;
            }
            else
            {
                if(*i > *(i-1))
                {
                    nPreCanCnt++;
                }
                else
                {
                    nPreCanCnt = 1;
                }
                nCandyCnt += nPreCanCnt;
                nSeqLen = 0;
                nMaxCntInSeq = nPreCanCnt;
            }
        }
    }
    return nCandyCnt;
}

// 3、
// T=O(n)
// S=O(1)

/*
      Ratings:
                                P = max(0,c)+1
              P = max(a,b)+1  | |
              |<-----       | | |
            | |     |     | | | |       P = max(d,0)+1
          | | | |   |   | | | | |       | | |
        | | | | | | ^ | | | | | | |     |<|-|--
      | | | | | | | | | | | | | | | | | | | | |
      Candies:                                ^
      1 2 3 4 5 3 2 1 2 3 4 5 6 3 2 1 1 2 1 1 END
      |-----|   |---|---------| * |-| *   * *
            a   b               1 c   d
*/
class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.size() < 2) return ratings.size();
        int result = 0;
        int up = 0;
        int down = 0;
        int lastDelta = 0;
        for (int i = 1; i < ratings.size(); i++) {
            int delta = 0;
            if (ratings[i-1] < ratings[i]) {
                delta = 1;
            } else if (ratings[i-1] > ratings[i]) {
                delta = -1;
            }
            if ((lastDelta < 0 && delta >= 0) || (lastDelta > 0 && delta == 0)) {
                // max(up, down) + 1 ? No. The next mountain start at the end.
                result += giveCandy(up) + giveCandy(down) + max(up, down);
                up = 0;
                down = 0;
            }
            if (delta > 0) {
                up++;
            } else if (delta < 0) {
                down++;
            } else {
                // Who says children with the same rating
                // should get the same amount of candies?
                // If the next child has more candies, the
                // next slope will take that into account.
                result++;
            }
            lastDelta = delta;
        }
        // max(up, down) + 1 ? Yes. There is no mountain next to it.
        result += giveCandy(up) + giveCandy(down) + max(up, down) + 1;
        return result;
    }
    int giveCandy(int n) {
        return n * (n + 1) / 2;
    }
};