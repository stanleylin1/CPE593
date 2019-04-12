/*
	Author: Stanley Lin
	I pledge my honor that I have abided by the Stevens Honor System.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;
class Point
{
  public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};
class GrowArray
{
  private:
    Point *data;
    int capacity;
    int used;
    void grow()
    {
        if (capacity > used)
        { //if capacity is big enough
            return;
        }
        Point *temp = data;
        data = new Point[2 * capacity];
        for (int i = 0; i < used; i++)
        {
            data[i] = temp[i];
        }
        capacity = capacity * 2; //double array capacity by two times
        delete[] temp;
    }

  public:
    GrowArray(int c = 0)
    {
        capacity = c;
        if (capacity == 0)
        {
            capacity = 1;
        }
        else
        {
            capacity = c;
        }

        data = new Point[capacity];
        used = 0;
    }
    void addEnd(Point p)
    {
        grow();
        data[used++] = p;
    }
    int length()
    {
        return used;
    }
    Point get(int position)
    {
        return data[position];
    }
    ~GrowArray()
    {
        delete[] data;
    }
};

class ConvexHull
{
  public:
    GrowArray *data;
    int capacity;
    double xmin;
    double xmax;
    double ymin;
    double ymax;

    ConvexHull(int c)
    {
        data = new GrowArray[c * c]; //create array of size c * c
        capacity = c;
    }

    void read(const string &file)
    {
        xmin = std::numeric_limits<double>::max();
        xmax = std::numeric_limits<int>::min();
        ymin = std::numeric_limits<double>::max();
        ymax = std::numeric_limits<int>::min();
        GrowArray ga(1);
        ifstream file1;
        string string1;
        double xpoint, ypoint;
        file1.open(file);
        if (!file1)
        {
            cerr << "Cannot open file" << endl;
            exit(1);
        }
        else
        {
            while (!file1.eof())
            {
                getline(file1, string1);
                istringstream iss(string1);
                iss >> xpoint >> ypoint;
                xmin = min(xmin, xpoint);
                xmax = max(xmax, xpoint);
                ymin = min(ymin, ypoint);
                ymax = max(ymax, ypoint);
                Point pp(xpoint, ypoint);
                ga.addEnd(pp);
            }
            int length = ga.length();
            double xrange = (xmax - xmin) / capacity;
            double yrange = (ymax - ymin) / capacity;

            for (int i = 0; i < length; i++)
            {
                Point p = ga.get(i);
                int xpos = (p.x - xmin) / xrange;
                int ypos = (p.y - ymin) / yrange;
                if (xpos == capacity)
                {
                    xpos = xpos - 1;
                }
                if (ypos == capacity)
                {
                    ypos = ypos - 1;
                }
                data[xpos * capacity + ypos].addEnd(p);
            }
            /*
            for (int i = 0; i < length; i++)
            {
                Point p = ga.get(i);
                int xpos = (p.x - xmin) / (xmax - xmin) * (capacity - 1);
                int ypos = (p.y - xmin) / (ymax - ymin) * (capacity - 1);
                data[((xpos * capacity) + ypos)].addEnd(p);
            }
            */
            file1.close();
        }
    }

    void printMinMax()
    {
        cout << "Minimum X:" << xmin << endl;
        cout << "Maximum X:" << xmax << endl;
        cout << "Minimum Y:" << ymin << endl;
        cout << "Maximum Y:" << ymax << endl;
    }
    void printAllListSizes() //print size of each list
    {
        cout << "Size of each list: " << endl;
        int numOfspaces = capacity * capacity;
        for (int i = 0; i < numOfspaces; i++)
        {
            cout << "p" << std::to_string(i + 1) << " contains:" << data[i].length();
            if (data[i].length() == 1)
            {
                cout << " element" << endl;
            }
            else
            {
                cout << " elements" << endl;
            }
        }
    }

    void printPerimeterClockWiseOrder()
    { //probably a better way to do this?
        cout << "Perimeter(Clockwise Order):" << endl;
        double xmin2, xmin3, xmin4, xmin5, xmax2, xmax3, xmax4, xmax5, ymin2, ymin3, ymin4, ymin5, ymax2, ymax3, ymax4, ymax5;
        xmin2 = std::numeric_limits<double>::max();
        double xmin2_save = std::numeric_limits<double>::max();
        xmax2 = std::numeric_limits<int>::min();
        double xmax2_save = std::numeric_limits<int>::min();
        ymin2 = std::numeric_limits<double>::max();
        double ymin2_save = std::numeric_limits<double>::max();
        ymax2 = std::numeric_limits<int>::min();
        double ymax2_save = std::numeric_limits<int>::min();
        xmin3 = std::numeric_limits<double>::max();
        double xmin3_save = std::numeric_limits<double>::max();
        xmax3 = std::numeric_limits<int>::min();
        double xmax3_save = std::numeric_limits<int>::min();
        ymin3 = std::numeric_limits<double>::max();
        double ymin3_save = std::numeric_limits<double>::max();
        ymax3 = std::numeric_limits<int>::min();
        double ymax3_save = std::numeric_limits<int>::min();
        xmin4 = std::numeric_limits<double>::max();
        double xmin4_save = std::numeric_limits<double>::max();
        xmax4 = std::numeric_limits<int>::min();
        double xmax4_save = std::numeric_limits<int>::min();
        ymin4 = std::numeric_limits<double>::max();
        double ymin4_save = std::numeric_limits<double>::max();
        ymax4 = std::numeric_limits<int>::min();
        double ymax4_save = std::numeric_limits<int>::min();
        xmin5 = std::numeric_limits<double>::max();
        double xmin5_save = std::numeric_limits<double>::max();
        xmax5 = std::numeric_limits<int>::min();
        double xmax5_save = std::numeric_limits<int>::min();
        ymin5 = std::numeric_limits<double>::max();
        double ymin5_save = std::numeric_limits<double>::max();
        ymax5 = std::numeric_limits<int>::min();
        double ymax5_save = std::numeric_limits<int>::min();

        for (int i = 0; i < capacity; i++) //top row
        {
            cout << "p" << std::to_string(i + 1) << ":" << endl;
            if (data[i].length() == 0)
            {
                continue;
            }
            for (int j = 0; j < data[i].length(); j++)
            {
                double xval = data[i].get(j).x;
                double yval = data[i].get(j).y;
                xmin2 = min(xmin2, xval);
                xmax2 = max(xmax2, xval);
                ymin2 = min(ymin2, yval);
                ymax2 = max(ymax2, yval);
            }
            cout << "Minimum X:" << xmin2 << endl;
            cout << "Maximum X:" << xmax2 << endl;
            cout << "Minimum Y:" << ymin2 << endl;
            cout << "Maximum Y:" << ymax2 << endl;
            xmin2 = xmin2_save;
            xmax2 = xmax2_save;
            ymin2 = ymin2_save;
            ymax2 = ymax2_save;
        }
        for (int i = capacity * 2 - 1; i <= capacity * capacity - capacity; i += capacity) //right column excluding first and last
        {
            cout << "p" << std::to_string(i + 1) << ":" << endl;
            if (data[i].length() == 0)
            {
                continue;
            }
            for (int j = 0; j < data[i].length(); j++)
            {
                double xval = data[i].get(j).x;
                double yval = data[i].get(j).y;
                xmin3 = min(xmin3, xval);
                xmax3 = max(xmax3, xval);
                ymin3 = min(ymin3, yval);
                ymax3 = max(ymax3, yval);
            }
            cout << "Minimum X:" << xmin3 << endl;
            cout << "Maximum X:" << xmax3 << endl;
            cout << "Minimum Y:" << ymin3 << endl;
            cout << "Maximum Y:" << ymax3 << endl;
            xmin3 = xmin3_save;
            xmax3 = xmax3_save;
            ymin3 = ymin3_save;
            ymax3 = ymax3_save;
        }
        for (int i = capacity * capacity - 1; i > capacity * capacity - capacity - 1; i--) //bottom row
        {
            cout << "p" << std::to_string(i + 1) << ":" << endl;
            if (data[i].length() == 0)
            {
                continue;
            }
            for (int j = 0; j < data[i].length(); j++)
            {
                double xval = data[i].get(j).x;
                double yval = data[i].get(j).y;

                xmin4 = min(xmin4, xval);
                xmax4 = max(xmax4, xval);
                ymin4 = min(ymin4, yval);
                ymax4 = max(ymax4, yval);
            }
            cout << "Minimum X:" << xmin4 << endl;
            cout << "Maximum X:" << xmax4 << endl;
            cout << "Minimum Y:" << ymin4 << endl;
            cout << "Maximum Y:" << ymax4 << endl;
            xmin4 = xmin4_save;
            xmax4 = xmax4_save;
            ymin4 = ymin4_save;
            ymax4 = ymax4_save;
        }
        for (int i = capacity * capacity - (2 * capacity); i >= capacity; i -= capacity) //left column excluding first and last
        {
            cout << "p" << std::to_string(i + 1) << ":" << endl;
            if (data[i].length() == 0)
            {
                continue;
            }
            for (int j = 0; j < data[i].length(); j++)
            {
                double xval = data[i].get(j).x;
                double yval = data[i].get(j).y;

                xmin5 = min(xmin5, xval);
                xmax5 = max(xmax5, xval);
                ymin5 = min(ymin5, yval);
                ymax5 = max(ymax5, yval);
            }
            cout << "Minimum X:" << xmin5 << endl;
            cout << "Maximum X:" << xmax5 << endl;
            cout << "Minimum Y:" << ymin5 << endl;
            cout << "Maximum Y:" << ymax5 << endl;
            xmin5 = xmin5_save;
            xmax5 = xmax5_save;
            ymin5 = ymin5_save;
            ymax5 = ymax5_save;
        }
    }
    ~ConvexHull()
    {
        delete[] data;
    }
};
int main()
{
    ConvexHull ch(16); // create GrowArray of 16*16
    ch.read("convexhullpoints.dat");
    ch.printMinMax();                  // print minx, maxx, miny, maxy for the entire dataset
    ch.printAllListSizes();            // tell us how many are in each list
    ch.printPerimeterClockWiseOrder(); // p1,p2,p3,p4, p8,p12,p16... perimeter only with xmin xmax ymin ymax
}
