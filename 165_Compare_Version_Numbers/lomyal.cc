
// 注意，1.2 和 1.2.0 是等价的

class Solution {
public:
    int compareVersion(string version1, string version2) {

        if (version1 == "0" && version2 == "0") {
            return 0;
        }

        string::size_type pos1, pos2;

        pos1 = version1.find('.');
        pos2 = version2.find('.');

        int n1 = stoi(version1.substr(0, pos1));
        int n2 = stoi(version2.substr(0, pos2));

        if (n1 < n2)
            return -1;
        else if (n1 > n2)
            return 1;
        else
            // 若本次截断前version无小数点，则传入"0"
            return compareVersion(pos1 == string::npos ? "0" : version1.substr(pos1 + 1),
                                  pos2 == string::npos ? "0" : version2.substr(pos2 + 1));
    }
};