#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define PI 3.1415926535897
double getRadian(int num)
{
    return num * (PI / 180);
}
int solution(double centerX, double centerY, double width, double height, double angle, vector<vector<double>> points)
{
    int answer = 0;
    double radian = getRadian(angle);
    double cos_ = cos(radian);
    double sin_ = sin(radian);

    for (int i = 0; i < points.size(); i++)
    {
        double x = points[i][0] - centerX;
        double y = points[i][1] - centerY;

        if (pow(x * cos_ + y * sin_, 2) / pow(width, 2) + pow(x * sin_ - y * cos_, 2) / pow(height, 2) <= 1)
        {
            answer++;
        }
    }

    return answer;
}
int main()
{

	cout << solution(5.0, 5.0, 5.0, 2.5, 127.0, { {-4.845,-4.03},{0.106,3.851 } });


	return 0;
}