#include <iostream>
using namespace std;

int main()
{
	const int MAX_SIZE = 1024;

	int size1, size2;
	do
	{
		cin >> size1 >> size2;
	} while (size1<1 || size1>MAX_SIZE || size2<1 || size2>MAX_SIZE);
	int coords1[2 * MAX_SIZE];
	int coords2[2 * MAX_SIZE];
	for (int i = 0; i < size1 * 2; i++)
	{
		do
		{
			cin >> coords1[i];
		} while (coords1[i] < 1);
	}
	for (int i = 0; i < size2 * 2; i++)
	{
		do
		{
			cin >> coords2[i];
		} while (coords2[i] < 1);
	}
	//finding the distances
	double distance1 = 0;
	double distance2 = 0;
	for (int i = 0; i < size1 * 2 - 2; i += 2)
	{
		int distA = coords1[i + 2] - coords1[i];
		if (distA < 0)
		{
			distA *= -1;
		}
		int distB = coords1[i + 3] - coords1[i + 1];
		if (distB < 0)
		{
			distB *= -1;
		}
		distance1 += sqrt(distA * distA + distB * distB);
	}
	for (int i = 0; i < size2 * 2 - 2; i += 2)
	{
		int distA = coords2[i + 2] - coords2[i];
		if (distA < 0)
		{
			distA *= -1;
		}
		int distB = coords2[i + 3] - coords2[i + 1];
		if (distB < 0)
		{
			distB *= -1;
		}
		distance2 += sqrt(distA * distA + distB * distB);
	}
	// checking
	double min = 0.01;
	double difference = distance1 - distance2;
	if (difference < 0)
	{
		difference *= -1;
	}
	if (difference < min)
	{
		cout << "true" << endl << distance1;
	}
	else
	{
		cout << "false";
	}

	return 0;
}