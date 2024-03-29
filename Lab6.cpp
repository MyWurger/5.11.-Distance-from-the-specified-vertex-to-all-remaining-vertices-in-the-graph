/********************************************************************************
 * � � � � � � � � � � � �   � � � � � �  �6  � �   5   � � � � � � �   �  +  + *
 *------------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                    *
 * Project Name  : Teor_Grph_Lab6                                               *
 * File Name     : Lab6. CPP                                                    *
 * Programmer(s) : ������� �.�.                                                 *
 * Modifyed By   :                                                              *
 * Created       : 06/10/23                                                     *
 * Last Revision : 12/10/23                                                     *
 * Comment(s)    : ���������, �������������� ���������� �� ��������� ������� �� *
 *                 ���� ��������� ������ � �����. ����������� ������ ��������   *
 *			       ������������ ��� ������, � ��������������� ���������� �����  *
 *			       ����.                                                        *
 ********************************************************************************/


#include <iostream>              // ����������� ������ �����/������
#include <vector>                // ������ � ��������� ��� �������� �������� ���������� � �������� ���������
#include <fstream>               // ������ � �������� �����/������ ��� �����
#include <iomanip>               // ���������� � ������������� setw
#include <string>                // ������ �� ��������
#include <queue>                 // ������ � ���������
#include <graphviz/gvc.h>        // ���������� Graphviz ��� ������������ ����������� ����� �� ������� ���������
#include <opencv2/opencv.hpp>    // ���������, ������������� ��� ������� OpenCv

using namespace std;             // ���������� ������������ ��� std



/*******************************************************************/
/*            � � � � � � � � � �    � � � � � � � � �             */
/*******************************************************************/

// ���� � ����� ����� ����������� ���������
// ������� �����
// ����� ��� ������� ���������
const char* FNAMEIN = "matrix_t6_001.txt";  // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t6_002.txt";
//const char* FNAMEIN = "matrix_t6_003.txt";
//const char* FNAMEIN = "matrix_t6_004.txt";
//const char* FNAMEIN = "matrix_t6_005.txt";
//const char* FNAMEIN = "matrix_t6_006.txt";
//const char* FNAMEIN = "matrix_t6_007.txt";
//const char* FNAMEIN = "matrix_t6_008.txt";
//const char* FNAMEIN = "matrix_t6_009.txt";
//const char* FNAMEIN = "matrix_t6_010.txt";

// ����� ��� ������ ���������
//const char* FNAMEIN = "list_of_adjacency_t6_010.txt";

// ����� ��� ������ Ш���
//const char* FNAMEIN = "list_of_edges_t6_001.txt";
//const char* FNAMEIN = "list_of_edges_t6_002.txt";
//const char* FNAMEIN = "list_of_edges_t6_003.txt";
//const char* FNAMEIN = "list_of_edges_t6_004.txt";
//const char* FNAMEIN = "list_of_edges_t6_005.txt";
//const char* FNAMEIN = "list_of_edges_t6_006.txt";
//const char* FNAMEIN = "list_of_edges_t6_007.txt";
//const char* FNAMEIN = "list_of_edges_t6_008.txt";
//const char* FNAMEIN = "list_of_edges_t6_009.txt";
//const char* FNAMEIN = "list_of_edges_t6_010.txt";

// ����� ��� ������ ���������
//const char* FNAMEIN = "list_of_adjacency_t6_010.txt";

// �������� �����
const char* FNAMEOUT = "Output_File.txt";

// ������������� ��� ������� ����������
const int INF = 10000;




/*******************************************************************/
/*      � � � � � � � � � �    � � � � � � � �    � � � � � �      */
/*******************************************************************/

 // ���������� ������� ��� ���������� ����� ������ �� �����
ifstream fin;
// ���������� ������� ��� ���������� ������ ������ � ����
ofstream fout;




/*******************************************************************/
/*                 � � � � � � � �   � � � � � � �                 */
/*******************************************************************/

/*------------------------------------------------------------------------*/
/*                 Graph                  */
/*----------------------------------------*/

class Graph
{
private:
	vector<vector<int>> m_matrix;                             // ���� � ��������� ����������� �������� ���������
	int m_size;                                               // ������ ������� ��������� (���������� ������ � �����)

public:
	// �����������
	Graph();
	// ����������
	~Graph();
	// ����������� ������ ��� ��������� �������� �������
	const int GetSize();
	// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
	bool is_directed();
	// �������, ������������ ������� ���������
	vector<vector<int>> adjacency_matrix();
	// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
	int Weight(int Vi, int Vj);
	// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
	bool is_edge(int Vi, int Vj);
	// �������, ������������ ������ ������, ������� ������� v;
	vector<int> adjacency_list(int v);
	// �������, ������������ ������ ���� ���� �����;
	vector<pair<int, int>> list_of_edges_pairs();
	// � �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	vector<pair<int, int>> list_of_edges(int v);
};




/*******************************************************************/
/*              � � � � � � � � �    � � � � � � �                 */
/*******************************************************************/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix);     // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ����� �� ����� � ���� ��������
void OpenImage(const vector<vector<int>>& adjacencyMatrix);       // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix);                     // �������, ������� ���������� ������� �� �����. �������� �� ��������

// ������ ������� � ������� ������
void Usloviya();

// ������ ������� ������ ���������
void Usloviya_1();

// ��������������� ������� ��� ���������� ������� ������� � ����������� �����������
int findMinDistance(vector<int> distance,                         // ������ ���������� �� ��������� ������� �� ���� ���������
	                vector<bool> visited);                        // ������������ ������

// �������� �������� ��� ���������� ����������� ���� � ������ ������ ������������� ����
void Dijkstra(vector<vector<int>> matrix,                         // �������� ������� ��� ����������� ������� ���� ����� ���������
	          int start,                                          // �������, � ������� ���������� ��������
	          vector<int>& ways);                                 // ���������� �� ������ ������� �� ���� ��������� � �����

// �������� �������-�����-����
void BellForMur(vector<vector<int>>graph,                         // ������� ��������� ����� � ����������� ������� ��������
	            vector<int>& ways,                                // ���������� ���������� �� ���� ������� �� ���� ���������
	            int start,                                        // ������ ����������� �������
	            bool print);                                      // ���� ������ � ����

// �������� ������
void Levit(vector<vector<int>> m_matrix,                          // ������� ��������� �����
	       vector<int>& ways,                                     // ������� ���������� �� ������ ������� �� ���� ���������
	       int StartVertex,                                       // �������, �� ������� ����� �������� ����������
	       bool print);                                           // ���� ������ � ����

// ������ ���������� �� ������ ������� �� ��������� �� �����
void print_distance(vector<int> distance,                         // ������ ���������� �� ������ ������� �� ���� ���������
	                int StartVertex);                             // ��������� �������, ����� �� �������� ���� ���� � ����

// ������ ���������� �� ������ ������� �� ��������� � ����
void print_distanceToFile(vector<int> distance,                   // ������ ���������� �� ������ ������� �� ���� ���������
	                      int StartVertex);                       // ��������� �������, ����� �� �������� ���� ���� � ����

// ����� �������  � ����
void PrintMatrToFile(vector<vector<int>> matrix);                 // �������, ������� ���������� ������� � ����. �������� �� ��������


// ����������� - ���������� ������� �� �����
Graph::Graph()
{
	fin.open(FNAMEIN);            // ��������� ������ � ������
	if (!fin.is_open())           // ���� �� ������
	{
		cout << "����� � ����� ������ ���. ���������� ����������� ������";
		fin.close();              // ������� ���� ��� ������
		system("pause");
		exit(0);                  // ���������� ��������, ��������������� ���� � caller
	}// if (!fin.is_open())

	int value;                    // ��������� ����������� ������
	char key;                     // ���� ��� �������� ������������� �������� ������� ����� � �����
	bool spravka = true;          // ���� ��� ������ ������� �� �����
	vector<int> row;              // ������ ��� ���������� ������������� �������� �� ����� ���������
	vector<vector<int>> matrix;   // ��������������� ������� ���������

	// ������ ����� ������� �����, ����� ������������ ������� ������� �� ����� �������
	while (spravka)
	{
		cout << "\x1b[30m � � � � � � �   � � � �   � � �   <h>   � � �   � � � � � �   � � � � � � � � � : \x1b[30m";
		// ������������ ��� ���� ��� ����, ����� ���� �������, ����� �������� �� ����� ����
		cin >> key;
		cout << "\n �� �����: " << key << endl;

		// � ����������� �� �������� �����
		switch (key)
		{
			// ������ � �������� ���������
		case('m'):
		case('M'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";
			// ��������� ��������� ����� �� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);

			}// while (fin >> value)

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������ �� ������� ����
		case('e'):
		case('E'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � �\n\n\x1b[30m\n";

			// ��������� �������� �� ����� � ������
			// � ������� ����� ���������� � ������������ ����� ��� ��������: ��������� �������, �������� ������� � ��� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);
			}// while (fin >> value)

			// ������� ���� ������
			fin.close();
			int size_m = m_matrix[m_matrix.size() - 1][0];    // ������ ������� ���������
			vector<vector<int>> vec_1(size_m);                // ������� ���������

			for (int i = 0; i < size_m; i++)                  // ����� ������ ������ ������ vec_1
			{
				vec_1[i].resize(size_m, 0);
			}// for i

			// ��������� ������� ���������
			for (int i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[0].size() == 3)                  // 3 ������� - ��� ��� �����, ���� �� �� ������, �� ������ �� = 1
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = m_matrix[i][2];
				}
				else
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = 1;
				}// if (m_matrix[0].size() == 3)
			}// for i

			// ���������� ������� ���������
			m_matrix = vec_1;
			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// �������� �� �������� ���������
		case('l'):
		case('L'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";

			// ������ �� ����� ���������
			string line;
			int rowNumber = 0;            // ����� ������� ������

			// ������ ����������
			while (getline(fin, line))
			{
				// ���� ������ ������, ��������� ������� ������ ������
				if (line.empty())
				{
					matrix.push_back(vector<int>(m_size, 0));
				}
				// ������ �� ������
				else
				{
					// ������ ������
					vector<int> row;
					// ������� ����� ��� ������ �������� �� ������ line. ����� �� ����� ������������ iss ������ � ���������� >> ��� ���������� �������� �� ������.
					istringstream iss(line);
					// ��������� �������� ��� ������
					int value;

					// ������ �������� �� ����� � �������� ��� � ������ ������
					while (iss >> value)
					{
						row.push_back(value);
					}// while

					// �������� ������ � �������
					matrix.push_back(row);
				}// if (line.empty()) 

				// ����������� ����� ������
				rowNumber++;
			}// while (getline(fin, line)) 

			// ���� �������� - ��������� ���
			fin.close();

			m_size = matrix.size();                         // ������ ������� ���������

			vector<vector<int>> vec_1(m_size);              // ��� ������� ��������� �������� m_size

			for (int i = 0; i < m_size; i++)                // ����� ������ ������ ������ ��� ������� ���������
			{
				// ��������� ��������������� ������� ������ �� ����� �������
				vec_1[i].resize(m_size, 0);
			}// for i

			for (int i = 0; i < m_size; i++)                 // ��������� ��� ������� ��������� 
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					// ������� � ��� ��������, ������� ����������� ��� ������ � �����
					vec_1[i][matrix[i][j] - 1] = 1;
				}// for j
			}// for i

			// �������� �������� � �������� ������� ���������
			for (int i = 0; i < m_size; i++)
			{
				row.clear();
				for (int j = 0; j < m_size; ++j)
				{
					row.push_back(vec_1[i][j]);
				}// fot j

				m_matrix.push_back(row);
			}// for i

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������������ ������ �������
		case('h'):
		case('H'):
		{
			// ��������� ���� ����� ��������� ������� �� ������
			spravka = true;
			// ������� �������
			Usloviya();
			break;
		}

		// ����� - ������������ ��� �� ��� ����. ����������� ��������� � �������
		default:
			cout << "\n\x1b[31m ������������� ��������� � ������� �������� �� ������ ������!!!\n\x1b[30m";
			// ��������� ���� ����������
			fin.close();
			exit(0);
		}
	}
	// ��������� ���� ����������
	fin.close();
	// ���������� ������ ���������/ ��������������� ������� ���������
	m_size = m_matrix.size();
}

// ����������
Graph::~Graph()
{
	// ������ ���� - ������� ������������ �������������
}

// ������ ��� ��������� �������� �������
const int Graph::GetSize()
{
	return(m_size);
}


// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
bool Graph::is_directed()
{
	// ��� �� �������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ��������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ���� �����������������, �� ������� �����������, ��� ��� �� ����� ����� ������ ������ ������������
			if (m_matrix[i][j] != m_matrix[j][i])
			{
				return true; // ������� ������������ ����� - ���� ���������������
			}// if (m_matrix[i][j] != m_matrix[j][i])

		}// for j

	}// for i

	return false; // �� ������� ������������ ����� - ���� �����������������
}


// �������, ������������ ������� ���������
vector<vector<int>> Graph::adjacency_matrix()
{
	return(m_matrix);
}


// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
int Graph::Weight(int Vi, int Vj)

{
	// ������ ������ ����� �� ��������� ���������� ��������
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		cout << "������! ����� ������� �� ����������\n";
		// ������� ������
		return(-1);
	}

	// ���� ���� ����������(� ������� ��������� �� 0)
	if (m_matrix[Vi][Vj] != 0)
	{
		cout << "��� ����� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		cout << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����� ����� ���������
		return(m_matrix[Vi][Vj]);
	}// if

	// ���� ���������������. ������� ��� ����
	else if ((m_matrix[Vi][Vj] != m_matrix[Vj][Vi]) && (m_matrix[Vi][Vj] != 0 || m_matrix[Vj][Vi] != 0))
	{
		cout << "���� ���������������. ���� ����. ����������� �����������. ��� ���� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����
		return(m_matrix[Vi][Vj]);
	}// else if

	// ����� ����� ��������� ��� - ������� ������� ��������� ����� 0
	else if (m_matrix[Vi][Vj] == 0)
	{
		cout << "����� ����� ��������� " << Vi << " � " << Vj << "���\n";
		// ������� ������� ��������
		return(m_matrix[Vi][Vj]);
	}// else if

	// ���������� ��������� ��������
	return(0);
}


// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
bool Graph::is_edge(int Vi, int Vj)
{
	// ������ ������ ����� �� ��������� ���������� �������� - ���� ���
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		// �������, ��� ���� ���
		return(false);
	}// if

	// ������� ������� ��������� �� ����� 0 - ����� ����
	if (m_matrix[Vi][Vj] != 0)
	{
		// ������������, ��� ����� ����
		return(true);
	}// if

	// ������� ������� ��������� ������� - ����� ���
	if (m_matrix[Vi][Vj] == 0)
	{
		// ������������, ��� ����� ���
		return(false);
	}// if
}


// �������, ������������ ������ ������, ������� ������� v;
vector<int> Graph::adjacency_list(int v)
{
	// ������ ������
	vector<int> adjList;

	// �������� �� ���� �������� � ���������, ���� �� ����� ����� �������� v � ������� ��������
	for (int i = 0; i < m_size; i++)
	{
		// ���� ���� - ������� ������� �� �������
		if (m_matrix[v][i] != 0)
		{
			// �������� ������� � ������
			adjList.push_back(i);
		}// if (m_matrix[v][i] != 0)

	}// for i

	// ���������� ������ ������� ������
	return adjList;
}


// �������, ������������ ������ ���� ���� �����;
vector<pair<int, int>> Graph::list_of_edges_pairs()
{
	// ������ ���, ���������� ����� � ���� ���� ����������� ��� ������
	vector<pair<int, int>> edges_pairs;
	// ��� �� ���� ��������� ������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ���� ��������� �������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ������� �� �������
			if (m_matrix[i][j] != 0)
			{
				// ��������� ���� ������
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)
		}// for j
	}// for i

	// ������� ������ ���� (��� ������)
	return(edges_pairs);
}


// �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
vector<pair<int, int>> Graph::list_of_edges(int v)
{
	int count = 0;
	vector<pair<int, int>> edges;         // ������ ��� ������(������ ����)
	vector<pair<int, int>> edges_inc;     // ������ ���� ����������� ������� v / ��������� �� ������� v
	edges = list_of_edges_pairs();        // �������� ��� ���� ������ �����

	// ������� ��� ����. ���� ���� �����������������, �� ��� ����� ���� (v,n) � (n, v) - ���������� ����������� ��� ������������� ������ �������. � ������� - ��������� ������� ������ ������
	for (int i = 0; i < edges.size(); i++)
	{
		// ������������� ������ ������� ����
		if (edges[i].first == v)
		{
			// �������� � ����� �����, ����������� ������� ������ �����
			edges_inc.push_back(edges[i]);
			// ����������� �������
			count = count + 1;
		}//if (edges[i].first == v)
	}//for i

	// ����������  ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	return(edges_inc);
}




/*------------------------------------------------------------------------*/
/*                �������               */
/*--------------------------------------*/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix)
{
	// ��������� ������ ������� ���������. ���� ������ 19, �� ������� �� ������� �������
	if (adjacencyMatrix.size() <= 19)
	{
		bool key = false;
		// ��������� ������� ����� �� ������, ����� ������, ����� �� ��������� �� ��� ������
		for (int i = 0; i < adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix.size(); j++)
			{
				// ���� ��� ����� ������ 1 ��� �������������, ������, ����� ��������� ��� � ������
				if (adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < 0)
					key = true;
			}
		}

		// ��������� ���� ��� ������ ����� � ������� DOT
		std::ofstream file;
		file.open("graph.dot");
		file << "digraph G {" << endl;

		if (key)
		{
			// ������� ���� � ��������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� �� ����� 0, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] != 0)
					{
						// ������� ����� � ��������� ���� � ������� DOT
						file << i << " -> " << j << " [label=\"" << adjacencyMatrix[i][j] << "\"];" << endl;
					}// if (adjacencyMatrix[i][j] != 0) 
				}// for j
			}// for i
		}

		else
		{
			// ������� ���� ��� �������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� ����� 1, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] == 1)
					{
						// ������� ����� ��� �������� ���� � ������� DOT
						file << i << " -> " << j << ";" << endl;
					}//if (adjacencyMatrix[i][j] == 1) 
				}// for j
			}// for i
		}// if key

		// ��������� ���� � ��������� ����������
		file << "}" << std::endl;
		file.close();

		// ���������� ����������� ����� � ������� PNG � ������� ������� DOT
		system("dot -Tpng graph.dot -o graph.png");
		cout << "\n\nGraph image saved as graph.png" << endl;
	}

	// �������, ��� ���� ������� ��� ���������
	else
	{
		cout << "\n\nGraph image is not saved as graph.png. It is too big" << endl;
	}
	// ���������� �������� ��� �������� ������ OpenCV
	return "graph.png";
}


// ����� ����� �� �����
void OpenImage(const vector<vector<int>>& adjacencyMatrix)
{
	// ��������� ����������� ������� ���������
	if (adjacencyMatrix.size() <= 19)
	{
		// �������� ���� � �����������, ���������� � ������� ������� drawGraph
		string imagePath = drawGraph(adjacencyMatrix);
		// ��������� ����������� � ������� OpenCV
		cv::Mat img = cv::imread(imagePath, -1);

		// ���������, ������� �� ��������� �����������
		if (img.empty()) {
			cout << "Could not open or find the image" << endl;
			return;
		}

		// ������� ���� � ��������� "Graph"
		cv::namedWindow("Graph", cv::WINDOW_NORMAL);
		// ���������� ����������� � ����
		cv::imshow("Graph", img);
		// ����, ���� ������������ ������ ����� �������
		cv::waitKey(0);
		// ��������� ����
		cv::destroyWindow("Graph");
		return;
	}// if (adjacencyMatrix.size() <= 19)
}


// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix)
{
	// ��������� ������� ����
	setlocale(0, "C");            // ������� ������ � �������� �������
	cout << setw(2) << setfill(' ') << (char)218 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)191 << endl;          // ����� ������� ���������� ������

	// ��� �� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(5) << setfill(' ');
		// ��� �� ��������
		for (int j = 0; j < matrix.size(); j++)
		{
			// ������� ������� �������
			cout << matrix[i][j] << " ";
		}// for j

		cout << endl;
	}// for i
	cout << setw(2) << setfill(' ') << (char)192 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;          // ����� ������� �������
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");

	// ���������� ��������� ��������
	return;
}


// ������ ������� � ������� ������
void Usloviya()
{
	cout << "\n\t\t\t\t/********************************************************************************\n";
	cout << "\t\t\t\t* � � � � � � � � � � � �   � � � � � �  �6  � �   5   � � � � � � �   �  +  +  *\n";
	cout << "\t\t\t\t*-------------------------------------------------------------------------------*\n";
	cout << "\t\t\t\t* Project Type  : Win64 Console Application                                     *\n";
	cout << "\t\t\t\t* Project Name  : Teor_Grph_Lab6                                                *\n";
	cout << "\t\t\t\t* File Name     : Lab6. CPP                                                     *\n";
	cout << "\t\t\t\t* Programmer(s) : ������� �.�.                                                  *\n";
	cout << "\t\t\t\t* Modifyed By   :                                                               *\n";
	cout << "\t\t\t\t* Created       : 06/10/23                                                      *\n";
	cout << "\t\t\t\t* Last Revision : 12/10/23                                                      *\n";
	cout << "\t\t\t\t********************************************************************************/\n";

	cout << "\n\t\t\t\t\t\t\t\x1b[31m   � � � � � � � : \n\n\x1b[30m";
	// ������� ������� � �������
	setlocale(0, "C");                       // ��������� ������� ����
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // ������� ������� ������ �����
	setlocale(LC_ALL, "Rus");                // ���������� ������� ����
	cout << " �������� ���� ������� �� ������:      ";
	setlocale(0, "C");                       // ��������� ������� ����
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // ������� ������ ������ ����� � ������������ ����� ������� � ��������� ���������
	cout << "  e " << (char)179 << "  Edges_list_file_path            ";                                                                                                         // ������� ������� ������ � ������ � �������� ��������� �������
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  m " << (char)179 << "  Adjacency_matrix_file_path      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  l " << (char)179 << "  Adjacency_list_file_path        ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  o " << (char)179 << "  Output_file_path                ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // ���������� ������� ����

	return;                                 // ���������� ��������� ��������
}

// ������ ������� ������ ���������
void Usloviya_1()
{
	// ������� ������� � �������
	setlocale(0, "C");                       // ��������� ������� ����
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // ������� ������� ������ �����
	setlocale(LC_ALL, "Rus");                // ���������� ������� ����
	cout << " �������� ���� ������� �� ������:      ";
	setlocale(0, "C");                       // ��������� ������� ����
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // ������� ������ ������ ����� � ������������ ����� ������� � ��������� ���������
	cout << "  d " << (char)179 << " Dijkstra 's algorithm            ";                                                                                                         // ������� ������� ������ � ������ � �������� ��������� �������
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  b " << (char)179 << " The Bellman-Ford-Moore algorithm ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  t " << (char)179 << " The Levite algorithm             ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // ���������� ������� ����

	return;                                 // ���������� ��������� ��������
}



// ��������������� ������� ��� ���������� ������� ������� � ����������� �����������
int findMinDistance(vector<int> distance,                         // ������ ���������� �� ��������� ������� �� ���� ���������
	                vector<bool> visited)                         // ������������ ������
{
	int minDistance = INF;                                        // ����������� ���������� - �������������
	int Dindex = -1;                                              // ���������� ����� �������� ������� �� ������� �������

	// ��� �� ���� ��������������� �������� � �������� ��, �� ������� ���������� ����������
	for (int i = 0; i < distance.size(); i++)
	{
		if (visited[i] == false && distance[i] < minDistance)
		{
			minDistance = distance[i];                            // ���������� ����������
			Dindex = i;                                           // ���������� � �����
		}// if (visited[i] == false && distance[i] < minDistance) 
	}// for i

	// ������� ��������� ��������
	return Dindex;
}


// �������� �������� ��� ���������� ����������� ���� � ������ ������ ������������� ����
void Dijkstra(vector<vector<int>> matrix,                         // �������� ������� ��� ����������� ������� ���� ����� ���������
	          int start,                                          // �������, � ������� ���������� ��������
	          vector<int>& ways)                                  // ���������� �� ������ ������� �� ���� ��������� � �����
{
	// ������ ������
	vector<int> error(1, -INF);

	// ���������� ������ � �����
	int Vertices = matrix.size();

	// ������ ���������� �� ������ �������. ���������� ��� ��������, � �� Vertices ���� �������� ���������������
	vector<int> distance(Vertices, INF);

	// �� ���� ������� ����� �� ��������
	vector<bool> visited(Vertices, false);


	// ��������� ������� ���� � ���� ������ �� ����� -> ��������� ����� ����
	distance[start] = 0;

	// ������ � ����� �� ������������� �� 1 ����� ������, ��� ��� ��������� ��� ���������
	for (int i = 0; i < Vertices - 1; i++)
	{
		// ������� ��������������� ������� ������ �� �������������, ��� ������� ���������� �� �������� ����������
		int current = findMinDistance(distance, visited);


		// ���� ��� ������ ��� ��������� - ���������� ��, ��� ��� ����
		if (current == -1)
		{
			ways = distance;
			return;
		}// if (current == -1)

		// ��� ������� ���������� � ������� ��� ����������
		visited[current] = true;

		for (int j = 0; j < Vertices; j++)
		{	// ���������� ��� ��� ������� ������� � ������(� ���������� �����) �� ������� ��������� �� ��������� ��������:
			// ���� ������� �� �������� � ���������� ���� �� ������ �������, ������ ����� ����� �� ������ ������� �� ����� ������ ���� ������, ��� ����, ������� ��� ������ �� ����� ��� ����� �������
			if (matrix[current][j] != 0 && visited[j] == false && distance[current] + matrix[current][j] < distance[j])
			{
				// ������������� ��� ����� ������� ����� �������� ����
				distance[j] = distance[current] + matrix[current][j];

			}// if
		}// for j
	}// for i

	// ��������� ���� ���� ��� ������ �������
	ways = distance;

	// ���������� ��������� ��������
	return;
}



// �������� �������-�����-����
void BellForMur(vector<vector<int>>graph,                         // ������� ��������� ����� � ����������� ������� ��������
	            vector<int>& ways,                                // ���������� ���������� �� ���� ������� �� ���� ���������
	            int start,                                        // ������ ����������� �������
                bool print)                                       // ���� ������ � ����
{
	// ��������� ������ 
	vector<int> distances(graph.size(), INF);

	// ���������� ������ �����, �� ������� ����� ����� ���������� ����
	int V = distances.size();

	// ��������� ������� ������� ���� � ���� ������ �� ����� -> ���������� �� �� ����� ����
	distances[start] = 0;

	// �������� �� ���� ������ ����� V-1 ���
	for (int i = 1; i <= V - 1; i++)
	{
		// �������� �� ���� �������� �����
		for (int u = 0; u < V; u++)
		{
			// �������� �� ���� ��������, ��������� � �������� u
			for (int v = 0; v < V; v++)
			{
				// ���� ���������� ����� (u, v) � ����� ���������� �� ������� v ������, ��� ������� ����������,
				// �� ��������� ������� ���������� �� ������� v
				if (graph[u][v] != 0 && distances[u] != INF && distances[u] + graph[u][v] < distances[v])
				{
					// ��������� ���������
					distances[v] = distances[u] + graph[u][v];
				}// if
			}// for v
		}// for u
	}// for i

	// �������������� ���� ��� ����������� ������������� ������
	// ���� � �������� ���������� ���������� ��������� ����� �������� ���� �� �������, �� ��� ��������, ��� ���������� ������������� ���� � �����.
	for (int u = 0; u < V; u++)
	{
		for (int v = 0; v < V; v++)
		{
			if (graph[u][v] != 0 && distances[u] != INF && distances[u] + graph[u][v] < distances[v])
			{
				// ��������� ������������� ����
				cout << "\n\x1b[31m Graph contains a negative cycle! \x1b[30m\n";
				// ������� � ����
				if (print)
				{
					fout << "\n Graph contains a negative cycle! \n";
				}
				// ����������� ��������� � ������� �� �������
				exit(0);
			}
		}
	}

	// ��������� ���� ���� ��� ������ �������
	ways = distances;

	// ���������� ��������� ��������
	return;
}


// �������� ������
void Levit(vector<vector<int>> m_matrix,                          // ������� ��������� �����
	       vector<int>& ways,                                     // ������� ���������� �� ������ ������� �� ���� ���������
	       int StartVertex,                                       // �������, �� ������� ����� �������� ����������
           bool print)                                            // ���� ������ � ����
{
	vector <int> distance(m_matrix.size(), INF);                  // ������ ����������. ���������� ��� - �������������
	distance[StartVertex] = 0;                                    // ���������� � ��������� ������� �� ���� = 0

	//vector <int> M0;       // ������ ��������������� ������, ������� ���� ���������� ��� ������� (������ ���� ������������ ������ sets, ��� � ��������� ���������)
	queue <int> M1;          // �������, ���������� �� ������� �����������  
	//vector <int> M2;       // ������ ���������������� ������������ ������� (������ ���� ������������ ������ sets, ��� � ��������� ���������)


	// ������, ������������ ������� ����� �������������� ����
	vector <int> count(m_matrix.size(), 0);
	// ������, ������� ���������� � ������ ��������� (M0,M1,M2) ����������� �������
	vector <int> sets(m_matrix.size());

	sets[StartVertex] = 1; // ��������� ������� ����������� ��������� M1
	M1.push(StartVertex);  // ����� ��������� ������� � ������� M1

	// ��������� ������ M0 ����� ���������, ����� ��������� �������
	for (int i = 0; i < m_matrix.size(); i++)
	{
		if (i != StartVertex)
		{
			// �������� � ���������, ��� ������� ����������� �������� ���������
			sets[i] = 0;
		}// if
	}// for i

	// ����������, ���� � ������� M1 ���� �������
	while (!M1.empty())
	{
		// �������� ��������� ������� �� ������� M1
		int V = M1.front();
		// �������� �� ������� ������ �������
		for (int j = 0; j < m_matrix.size(); j++)
		{
			// ���� ����� ������� �������� � ��������� - �� �������. ��������� ������� ����� �������
			if (m_matrix[V][j] != 0)
			{
				// ���� ���� ��������� ����� ����������� ��������� M0
				if (sets[j] == 0)
				{
					// ������������� ���������� �� ���� ����� ������� V
					distance[j] = distance[V] + m_matrix[V][j];
					// ����������� ����� ����� �� ������ ������� (����������� �� ����������)
					count[j] = count[j] + 1;
					M1.push(j);  // ������� ������ � ������� �1 (�����������)
					sets[j] = 1; // ������� ������ � ������� �1 (����)

					// ���� ����� ����� �� ���� ������� ��������� ����� ������ -> � ����� ������������ ���� �������������� ����
					if (count[j] > m_matrix.size())
					{
						cout << "\n\x1b[31m Graph contains a negative cycle! \x1b[30m\n";

						// ������� � ����
						if (print)
						{
							fout << "\n Graph contains a negative cycle! \n";
						}
						// ����������� ��������� �� �������
						exit(0);
					}// if
				}// if

				// ���� ���� ��������� ������� ����������� ��������� M1
				else if (sets[j] == 1)
				{
					// �������: ������ �� ���������� �� ������� ������� �� ������ ��� ���� ����� ������ ��� ������, ��� ��� ����������.
					// �������� ����������� ��������
					distance[j] = min(distance[j], distance[V] + m_matrix[V][j]);
				}// else if

				// ���� ���� ��������� ������� ����������� ��������� M2
				else if (sets[j] == 2)
				{
					// ���� ����� ���������� ������ ������� ����������
					if (distance[j] > distance[V] + m_matrix[V][j])
					{
						// ������������� ����� ���������� �� ������� M2
						distance[j] = distance[V] + m_matrix[V][j];

						M1.push(j);   // ������� � � ������� �1   (����������� �������)
						sets[j] = 1;  // ������� � � ������� �1   (������� �����)
						// ����������� ����� ����� �� ������ ������� (����������� �� ����������)
						count[j] = count[j] + 1;

						// �������� count[j] ���������� ������, ��� ������ ����� (m_matrix.size()), ��� �������� ������� ��������������
						// ����� � �����. � ����� ������ ��������� ��������� � ������� �������������� �����, � ��������� ��������� ���� ������.
						if (count[j] > m_matrix.size())
						{
							cout << "\n\x1b[31m Graph contains a negative cycle! \x1b[30m\n";

							// ������� � ����
							if (print)
							{
								fout << "\n Graph contains a negative cycle! \n";
							}

							// ��������� ��������� �� �������
							exit(0);
						}// if (count[j] > m_matrix.size())

					}// if (distance[j] > distance[V] + m_matrix[V][j]) 

				}// else if (sets[j] == 2)

			}//if (m_matrix[V][j] != 0)

		}// for j

		M1.pop();        // ������� ������ ������� �������
		sets[V] = 2;     // ��������, ��� ������� V ����������� ��������� M2 - ��� ����������

	}// while

	// ��������� ���� ���� ��� ������ �������
	ways = distance;

	// ���������� ��������� ��������
	return;
}


// ������ ���������� �� ������ ������� �� ��������� �� �����
void print_distance(vector<int> distance,                         // ������ ���������� �� ������ ������� �� ���� ���������
	                int StartVertex)                              // ��������� �������, ����� �� �������� ���� ���� � ����
{
	// ��� �� ���� ��������� ������� ����������
	for (int i = 0; i < distance.size(); i++)
	{
		// ���� ����� ������ ������� �� ��������� �� ��������� (�� ����� �������� ���� � ����)
		if (i != StartVertex)
		{
			// ������� � �� ����� ���� � ����������
			cout << " " << StartVertex + 1 << " - " << i + 1 << ": " << distance[i] << endl;
		}// if
	}// for i

	// ���������� ��������� ��������
	return;
}


// ������ ���������� �� ������ ������� �� ��������� � ����
void print_distanceToFile(vector<int> distance,                   // ������ ���������� �� ������ ������� �� ���� ���������
	                      int StartVertex)                        // ��������� �������, ����� �� �������� ���� ���� � ����
{
	// ��� �� ���� ��������� ������� ����������
	for (int i = 0; i < distance.size(); i++) // ����� ���������
	{
		// ���� ����� ������ ������� �� ��������� �� ��������� (�� ����� �������� ���� � ����)
		if (i != StartVertex)
		{
			// ������� � ���� ���� � ����������
			fout << " " << StartVertex + 1 << " - " << i + 1 << ": " << distance[i] << endl;
		}// if
	}// for i

	// ���������� ��������� ��������
	return;
}


// ����� �������  � ����
void PrintMatrToFile(vector<vector<int>> matrix)                 // �������, ������� ���������� ������� � ����. �������� �� ��������
{
	// ��� �� ������� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		fout << " ";
		// ��� �� �������� �������
		for (int j = 0; j < matrix.size(); j++)
		{
			// ������� ��������� ������� ������� � ����
			fout << matrix[i][j] << " ";
		}// for j
		fout << endl;
	}// for i

	// ���������� ��������� ��������
	return;
}

/*------------------------------------------------------------------------*/
/*            ������� �������           */
/*--------------------------------------*/
int main()
{
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");
	// ���� ������� - �����
	system("color F0");
	// ���� ������ � ����. ���������� - ������ ���
	bool print = false;
	// ����, �������� ������������� ��� ������
	char letter;
	cout << "\t\t\t\t\t\t\x1b[34m    � � � � � �   �   � � � � � � �\x1b[30m\n\n\n";
	// ������� ������ �����. ����������� ���������� ��-���������
	Graph NewGraph;

	// �����, ����� �� ������������ �������� � ���� ����������� ����������
	cout << " ������ �� �� �������� ������ � ����? ������� <o>, ���� ������, ��� ����� ������ ������ - ���� ���. �������: ";
	cin >> letter;                             // ���� �������������
	cout << "\n �� �����: " << letter;         // ���-������

	// ���� ������������ ����� ��������. ������������� ����
	if (letter == 'o' || letter == 'O')
	{
		// ������������� ���� ����, ��� ����� �������� ������ � ����
		print = true;

		fout.open(FNAMEOUT);           // ��������� ������ � ������
		if (!fout.is_open())           // ���� �� ������
		{
			cout << "����� � ����� ������ ���. ���������� ����������� ������";
			fin.close();               // ������� ���� ��� ������
			system("pause");
			exit(0);                   // ���������� ��������, ��������������� ���� � caller
		}// if (!fout.is_open())
	}// if (letter == 'o' || letter == 'O')

	// ������� ������� ��������� �� ������ �� ����� �� �����
	cout << "\n\n\t\t\t\t\t\x1b[35m � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\x1b[30m\n\n";
	PrintMatrix(NewGraph.adjacency_matrix());

	// ������������ ������� �������� � ����
	if (print)
	{
		// ������� ����� ���������� � ����
		fout << "\t\t\t\t\t\t    � � � � � �   �   � � � � � � �\n\n\n";
		fout << "\n\n � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\n\n";
		// ������� ������� ��������� � ����
		PrintMatrToFile(NewGraph.adjacency_matrix());
		fout << endl;
	}// if

	// ������ ��������������� � �����������
	vector<int> distances; // ������ ���������� �� ������ ������� �� ���� ���������
	char key;              // ���� ������������ ��� ������ ���������
	char beg_vertex;       // ����� �� ������������ ������ ��������� �������
	int Start_Vertex;      // ��������� ������� ��� ������ ���������
	cout << "\n\x1b[33m  � � � � � � �   � � � �  � �  � � � � � � � � �  � � � � � �: \x1b[30m\n";

	// ����� �������� � ��������� ��� ������ �����
	Usloviya_1();
	cout << " ����: ";
	// ���� ����� ������ ��������� ��� ������
	cin >> key;
	cout << " �� �����: " << key << endl;
	// ������ �� ����� ������ ������������, �.� ��� ��������� ������� ��������� �������� �������� �� �����
	cout << " ������ �� �� ������ ��������� �������? ������� <n>, ���� ������, ��� ����� ������ ������ - ���� ���. �������: ";
	// ���� ������� ������������
	cin >> beg_vertex;

	// ���� ������������ ������� ������ ��������� �������
	if (beg_vertex == 'n' || beg_vertex == 'N')
	{
		// ������ ������������ ������ ����� ��������� �������
		cout << "\n\n\x1b[32m � � � � � � �   � � � � �   � � � � � � � � �   � � � � � � �: \x1b[30m";
		// ���� ������ ��������� �������
		cin >> Start_Vertex;
		// ���-������
		cout << "\n �� �����: " << Start_Vertex << endl;
	}
	// ����� - ������������ �� ������� �������� ��������� ������� - ����� �� ��������� � �������
	else
	{
		cout << "\n\x1b[31m ������!!!��������� �� ����� �������� ��� ������� ��������� �������. ������� � ����� � ������������� ���������!!!\x1b[30m\n ";
		// ������� � �������
		return -1;
	}// if

	// ��� ������������ ������� ����� �� 1 ������, ��� ��, � �������� �� ����� �������� � ���������
	Start_Vertex = Start_Vertex - 1;
	//������� ���� �������������� ����
	bool weight = false;
	// ��������� ������� ���� �������������� ���� � �����
	for (int i = 0; i < NewGraph.GetSize(); i++)
	{
		// ��� �� ������� ������� ���������
		for (int j = 0; j < NewGraph.GetSize(); j++)
		{
			// ���� ��������� ������� ������� - ������������� - �������� ����
			if (NewGraph.adjacency_matrix()[i][j] < 0)
			{
				weight = true;
			}// if
		}// for j
	}// for j


	// � ����������� �� ����� ������ ��������� ��������� ����������� �������
	switch (key)
	{
	
	// ������������ ������ ��������
	case('d'):
	case('D'):
	{
		// �������� ������� ���� �������������� ���� - �������� � ���� �� ��������
		if(weight)
		{ 
			cout << "\n\x1b[31m ������!!! �������� �� �������� ��� ����� � �������������� ������. �������� ������ ��������! � ������������� ���������\n\x1b[30m";
			return -2;
		}

		cout << "\n\t\t\t\t\t\t\t\x1b[35m � � � � � � � �   � � � � � � � � \n\x1b[30m";
		// �������� �������� ��������, ���� ��� ���� �������������� ����
		Dijkstra(NewGraph.adjacency_matrix(), Start_Vertex, distances);
		break;
	}

	// ������� �������� ������� - ����� - ����
	case('b'):
	case('B'):
	{
		cout << "\n\t\t\t\t\t\t\x1b[35m � � � � � � � �   � � � � � � � � - � � � � � - � � � �\n\x1b[30m";
		// �������� ��������. ������-����-��� ����� �������� � �������������� ������
		BellForMur(NewGraph.adjacency_matrix(), distances, Start_Vertex, print);
		break;
	}
	
	// ������� �������� ������
	case('t'):
	case('T'):
	{
		cout << "\n\t\t\t\t\t\t\t\x1b[35m   � � � � � � � �   � � � � � � \n\x1b[30m";
		// �������� ��������. ����� ����� �������� � �������������� ������
		Levit(NewGraph.adjacency_matrix(), distances, Start_Vertex, print);
		break;
	}

	// ����� - ������������ ��� �� ��� ����. ����������� ��������� � �������
	default:
		cout << "\n\x1b[31m ������������� ��������� � ������� �������� �� ������ ������ ��� ������ ���������!!!\n\x1b[30m";
		// ��������� ���� ����������
		exit(0);
	}

	// ������� ���������� ������ ����������, ���������� ����� ������ ������ �� ���������� �� �����
	cout << "\n\n\t\t\t\t\t\t\t\x1b[36m � � � � � �   � � � � � � � � � �:\x1b[30m\n\n";
	
	// ��� ���� �������������� ����
	if (!weight)
	{
		cout << " Graph does not contain edges with negative weight.\n\n";
		if (print)
		{
			fout << " Graph does not contain edges with negative weight.\n\n";
		}// if
	}

	// ���� �������������� ���� ����
	else
	{
		cout << " Graph contains edges with negative weight.\n\n";
		if (print)
		{
			fout << " Graph contains edges with negative weight.\n\n";
		}// if
	}

	print_distance(distances, Start_Vertex);

	// ������� ���������� ������ ����������, ���������� ����� ������ ������ �� ���������� � ����
	if (print)
	{
		fout << "\n\n\t\t\t\t\t\t\t\t � � � � � �   � � � � � � � � � �:\n\n";
		print_distanceToFile(distances, Start_Vertex);
	}// if

	// ������� �������� � ������ �� �����
	OpenImage(NewGraph.adjacency_matrix());

	// ������� ���� ��� ������
	fout.close();
	// ���������� ��������� �������� � �������
	return 0;
}
