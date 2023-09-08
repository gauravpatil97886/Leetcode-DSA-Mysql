public class Solution {
    public IList<string> FizzBuzz(int n) {
        IList<string> result = new List<string>();

        for (int i = 1; i <= n; i++) {
            string str = "";
            if (i % 3 == 0) str += "Fizz";
            if (i % 5 == 0) str += "Buzz";
            if (str == "") str = i.ToString();
            result.Add(str);
        }

        return result;
    }
}
