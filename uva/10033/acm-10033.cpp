/**
 * Title: Interpreter
 * URL: http://online-judge.uva.es/p/v100/10033.html
 * Resources of interest:
 * Solver group: David
 * Contact e-mail: dncampo at gmail dot com
 * Description of solution:
   + Se utilizan vector<string> para los registros y para la memoria.
	+ Se utilizan strings para representar cada palabra de memoria o registro, para poder acceder de 
	forma sencilla a cada componente de dicha palabra.
	+ Se codificó una función para cada uno de los distintos tipos de operaciones para facilitar el
	seguimiento y eventual depuración.

**/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


struct PC {
	vector<string> RAM;
	vector<string> REGS;
};

unsigned to_unsigned (string& val) {
	unsigned u;
	istringstream conv (val);
	conv >> u;
	return u;
}

string to_str (int val) {
	string s;
	stringstream out;
	out << val;
	s = out.str();
	while (s.size () < 3) s = '0' + s;
	return s;
}

void op2 (PC &pc, string op, unsigned &pos) {
	pc.REGS[ op[1] - '0' ] = to_str (op[2] - '0');
	pos++;
}

void op3 (PC &pc, string op, unsigned &pos) {
	unsigned val1 = to_unsigned (pc.REGS[ op[1] - '0' ]); 
	val1 += op[2] - '0';
	val1 %= 1000; 
	pc.REGS[ op[1] - '0' ] = to_str (val1);
	pos++;
}

void op4 (PC &pc, string op, unsigned &pos) {
	unsigned val1 = to_unsigned (pc.REGS[ op[1] - '0' ]);
	val1 *= op[2] - '0';
	val1 %= 1000;
	pc.REGS[ op[1] - '0' ] = to_str (val1);
	pos++;
}

void op5 (PC &pc, string op, unsigned &pos) {
	pc.REGS[ op[1] - '0' ] = pc.REGS[ op[2] - '0' ]; 
	pos++;
}

void op6 (PC &pc, string op, unsigned &pos) {
	unsigned val1 = to_unsigned (pc.REGS[ op[1] - '0' ]);
	unsigned val2 = to_unsigned (pc.REGS[ op[2] - '0' ]);
	val1 += val2;
	val1 %= 1000;
	pc.REGS[ op[1] - '0' ] = to_str (val1);
	pos++;
}

void op7 (PC &pc, string op, unsigned &pos) {
	unsigned val1 = to_unsigned (pc.REGS[ op[1] - '0' ]);
	unsigned val2 = to_unsigned (pc.REGS[ op[2] - '0' ]);
	val1 *= val2; val1 %= 1000;
	pc.REGS[ op[1] - '0' ] = to_str (val1);
	pos++;
}

void op8 (PC &pc, string op, unsigned &pos) {
	unsigned val1 = to_unsigned (pc.REGS[ op[2] - '0' ]);
	pc.REGS[ op[1] - '0' ] = pc.RAM[val1];
	pos++;
}

void op9 (PC &pc, string op, unsigned &pos) {
	unsigned val1 = to_unsigned (pc.REGS[ op[2] - '0' ]);
	pc.RAM[val1] = pc.REGS[ op[1] - '0'];
	pos++;
}

void op0 (PC &pc, string op, unsigned &pos) {
	unsigned val1 = to_unsigned (pc.REGS[ op[1] - '0' ]);
	unsigned val2 = to_unsigned (pc.REGS[ op[2] - '0' ]);
	pos =  ( (0 != val2)? pos = val1: pos + 1);
}

unsigned run (PC &pc) {
	unsigned pos = 0, executed = 0;
	while (pc.RAM[pos] != "100") {
		string op = pc.RAM[pos];

		switch (op[0]) { //perform the correct operation
			case '2':  op2 (pc, op, pos); break;
			case '3':  op3 (pc, op, pos); break;
			case '4':  op4 (pc, op, pos); break;
			case '5':  op5 (pc, op, pos); break;
			case '6':  op6 (pc, op, pos); break;
			case '7':  op7 (pc, op, pos); break;
			case '8':  op8 (pc, op, pos); break;
			case '9':  op9 (pc, op, pos); break;
			case '0':  op0 (pc, op, pos); break;
		}
		executed++; //an instruction has been executed
	}

	return ++executed; //halt counts, too :)
}

int main () {
	unsigned n_cases;
	cin >> n_cases; cin.ignore (); cin.ignore ();
	
	for (unsigned i = 0; i < n_cases; i++) {

		PC pc; //creates the pc
		pc.RAM = vector<string> (1000, "000");
		pc.REGS = vector<string> (10, "000");

		unsigned pos = 0;
		string line;
		getline (cin, line);
		while (line != "") { //read mem's values
			pc.RAM[pos++] = line;
			getline (cin, line);
		}
		cout << run (pc) << endl; if (i < n_cases - 1) cout << endl;
	}

}