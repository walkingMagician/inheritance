#include<iostream>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");

#ifdef WRITE_TO_FILE
	cout << "hello world" << endl;
	std::ofstream fout;		// 1)создаём поток
	fout.open("file.txt", std::ios_base::app);	// 2) открываем поток 
	fout << "hello world" << endl;	// 3) пишем в поток 
	fout.close();			// 4)  закрываем поток 

	system("notepad File.txt");
#endif

	std::ifstream fin("file.txt");	// 1) открытие потока можно совместить с созданием потока
	if (fin.is_open())
	{
		// TODO: read from file
		while (!fin.eof())
		{
			const int SIZE = 256;
			char sz_buffer[SIZE]{};
			//fin >> sz_buffer;	// для fin, так же как и для cin пробел является разделителем,
								// и для того, чтобы прочесть строку с пробелами, вместо cin используется cin.getline()
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
		
}