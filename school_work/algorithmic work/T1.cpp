#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
private:
	int row, col;
	vector < vector <double> > data;
	void judge(const Matrix &);
public:
	Matrix();
	Matrix(int, int, const vector < vector <double> > &);
	~Matrix();
	friend istream & operator >> (istream &, Matrix &);
	friend ostream & operator << (ostream &, const Matrix &);
	const Matrix operator = (const Matrix &);
	const Matrix operator + (const Matrix &);
	const Matrix operator += (const Matrix &);
	const Matrix operator - (const Matrix &);
	const Matrix operator -= (const Matrix &);
	const Matrix operator * (const Matrix &);
	const Matrix operator * (const double);
	friend const Matrix operator * (const double, const Matrix &);
	const Matrix operator *= (const Matrix &);
	const Matrix operator *= (const double);
	const Matrix operator / (const double);
	const Matrix operator /= (const double);
	void Transpose();
};

Matrix::Matrix()
{
	int row = 0, col = 0;
	vector <double> v;
	v.push_back(0);
	data.push_back(v);
	v.clear();
}

Matrix::Matrix(int x, int y, const vector <vector <double> > & T)
{
	row = x;
	col = y;
	data.clear();
	data = T;
}

Matrix::~Matrix()
{
	data.clear();
}

istream & operator >> (istream & input, Matrix & T)
{
	T.data.clear();
	cout << "please input the Rows and the Cols of the Matrix, then the row" << endl;
	input >> T.row >> T.col;
	int temp, i, j;
	vector <double> v;
	for (i = 0; i < T.row; i++)
	{
		for (j = 0; j < T.col; j++)
		{
			input >> temp;
			v.push_back(temp);
		}
		T.data.push_back(v);
		v.clear();
	}
	return input;
}

ostream & operator << (ostream & output, const Matrix & T)
{
	unsigned i, j;
	for (i = 0; i < T.row; i++)
	{
		for (j = 0; j < T.col; j++)
			output << T.data[i][j] << '\t';
		output << endl;
	}
	return output;
}

const Matrix Matrix::operator = (const Matrix & T)
{
	row = T.row;
	col = T.col;
	data.clear();
	data = T.data;
	return {0, 0, vector < vector <double> > (0)};
}

const Matrix Matrix::operator + (const Matrix & T)
{
	if (row != T.row || col != T.col)
	{
		cout << "error" << endl;
		return {0, 0, vector < vector <double> > (0)};
	}
	vector < vector <double> > t;
	vector <double> v;
	int temp;
	unsigned i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			temp = data[i][j] + T.data[i][j];
			v.push_back(temp);
		}
		t.push_back(v);
	}
	return {row, col, t};
}

const Matrix Matrix::operator += (const Matrix & T)
{
	if (row != T.row || col != T.col)
	{
		cout << "error" << endl;
		return {0, 0, vector < vector <double> > (0)};
	}
	unsigned i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			data[i][j] = data[i][j] + T.data[i][j];
	}
	return *this;
}

const Matrix Matrix::operator - (const Matrix & T)
{
	if (row != T.row || col != T.col)
	{
		cout << "error" << endl;
		return {0, 0, vector < vector <double> > (0)};
	}
	vector < vector <double> > t;
	vector <double> v;
	int temp;
	unsigned i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			temp = data[i][j] + T.data[i][j];
			v.push_back(temp);
		}
		t.push_back(v);
		v.clear();
	}
	return {row, col, t};
}

const Matrix Matrix::operator -= (const Matrix & T)
{
	if (row != T.row || col != T.col)
	{
		cout << "error" << endl;
		return {0, 0, vector < vector <double> > (0)};
	}
	unsigned i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			data[i][j] = data[i][j] - T.data[i][j];
	}
	return *this;
}

const Matrix Matrix::operator * (const Matrix & T)
{
	if (col != T.row)
	{
		cout << "error" << endl;
		return {0, 0, vector < vector <double> > (0)};
	}
	vector < vector <double> > t;
	vector <double> v;
	int temp;
	unsigned i, j, k;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			temp = 0;
			for (k = 0; k < col; k++)
				temp += data[i][k] * T.data[k][j];
			v.push_back(temp);
		}
		t.push_back(v);
		v.clear();
	}
	return {row, T.col, t};
}

const Matrix Matrix::operator * (const double num)
{
	vector < vector <double> > t;
	vector <double> v;
	unsigned i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			v.push_back(data[i][j] * num);
		t.push_back(v);
		v.clear();
	}
	return {row, col, t};
}

const Matrix operator * (const double num, const Matrix & T)
{
	vector < vector <double> > t;
	vector <double> v;
	unsigned i, j;
	for (i = 0; i < T.row; i++)
	{
		for (j = 0; j < T.col; j++)
			v.push_back(T.data[i][j] * num);
		t.push_back(v);
		v.clear();
	}
	return {T.row, T.col, t};
}

const Matrix Matrix::operator *= (const double num)
{
	unsigned i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			data[i][j] *= num;
	}
	return *this;
}

const Matrix Matrix::operator *= (const Matrix & T)
{
	*this = *this * T;
	return *this;
}

const Matrix Matrix::operator / (const double num)
{
	vector < vector <double> > t;
	vector <double> v;
	unsigned i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			v.push_back(data[i][j] / num);
		t.push_back(v);
		v.clear();
	}
	return {row, col, t};
}

const Matrix Matrix::operator /= (const double num)
{
	unsigned i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			data[i][j] /= num;
	}
	return *this;
}

void Matrix::Transpose()
{
	vector < vector <double> > t;
	vector <double> v;
	unsigned i, j;
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
			v.push_back(data[j][i]);
		t.push_back(v);
		v.clear();
	}
	data.clear();
	data = t;
}

int main()
{
	Matrix temp1, temp2;
	cin >> temp1 >> temp2;
	cout << temp1 * temp2;
	cout << temp1 * 2;
	cout << temp2 / 2;
	temp2 /= 2;
	temp1 *= 3;
	cout << temp1 << temp2;
	return 0;
}
