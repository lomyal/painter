
// 1、C++ 3ms
class Solution {
public:
    vector<vector<int> > generate(int numRows) {

        vector<vector<int> > tri = {};
        if (numRows == 0) {
            return tri;
        }

        vector<int> firstLayer= {1};
        tri.push_back(firstLayer);
        if (numRows == 1) {
            return tri;
        }

        for (int k = 1; k < numRows; k++) {
            vector<int> upperLayer = tri[k - 1];
            vector<int> currentLayer(upperLayer.size() + 1, 1);

            // 填满本层的前一半元素（不包括第一个元素，包括中间的元素（元素个数为奇数时））
            for (int i = 0; i < (int)upperLayer.size() / 2; i++) {
                currentLayer[i + 1] = upperLayer[i] + upperLayer[i + 1];
            }

            for (int i = 0, j = (int)upperLayer.size(); i < j; i++, j--) {
                currentLayer[j] = currentLayer[i];
            }

            tri.push_back(currentLayer);
        }

        return tri;
    }
};

// 2、Python 40ms
class Solution:
    def generate(self, numRows):
        outter = []
        for i in xrange(numRows):
            if i == 0:
                inner = [1]
            else:
                inner = outter[i - 1][:]
                for j in xrange(len(inner) - 1, 0, -1):
                    inner[j] = inner[j] + inner[j - 1]
                inner.append(1)
            outter.append(inner)

