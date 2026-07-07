class Solution {
public:
    bool isIPv4(string ip) {
        vector<string> parts;
        string temp;

        for (char c : ip) {
            if (c == '.') {
                parts.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        parts.push_back(temp);

        if (parts.size() != 4) return false;

        for (string s : parts) {
            if (s.empty() || s.size() > 3) return false;

            if (s.size() > 1 && s[0] == '0')
                return false;

            for (char c : s)
                if (!isdigit(c))
                    return false;

            int num = stoi(s);
            if (num < 0 || num > 255)
                return false;
        }

        return true;
    }

    bool isIPv6(string ip) {
        vector<string> parts;
        string temp;

        for (char c : ip) {
            if (c == ':') {
                parts.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        parts.push_back(temp);

        if (parts.size() != 8) return false;

        for (string s : parts) {
            if (s.empty() || s.size() > 4)
                return false;

            for (char c : s) {
                if (!(isdigit(c) ||
                      (c >= 'a' && c <= 'f') ||
                      (c >= 'A' && c <= 'F')))
                    return false;
            }
        }

        return true;
    }

    string validIPAddress(string queryIP) {
        if (count(queryIP.begin(), queryIP.end(), '.') == 3 && isIPv4(queryIP))
            return "IPv4";

        if (count(queryIP.begin(), queryIP.end(), ':') == 7 && isIPv6(queryIP))
            return "IPv6";

        return "Neither";
    }
};