#include <iostream>
#include <string>
//DDS
#include <RoqmeReaderImpl.h>
#include "RoqmeDDSManager.h"
#include "RoqmeConstantDefinitions.h"
#include "RoqmeDataWriter.h"
#include <RoqmeWriterImpl.h>
#include "RoqmeDDSListener.h"
//DDS
using namespace std;

int main(int argc, char **argv)
{
	bool exit = false;
	cout << "Test DDS Publisher" << endl;
	char option = -1;
	int int_val = -1;
	uint uint_val = -1;
	double double_val = 0.0;
	bool bool_val = false;
	string enum_val = "";
	double estimate_val = 0.0;
	string obs_val = "";

	string nameContext = "";
	Roqme::RoqmeDDSManager roqmeManager;
	RoqmeDDSTopics::RoqmeEventContext event_data;
	RoqmeDDSTopics::RoqmeIntContext int_data;
	RoqmeDDSTopics::RoqmeDoubleContext double_data;
	RoqmeDDSTopics::RoqmeBoolContext bool_data;
	RoqmeDDSTopics::RoqmeEnumContext enum_data;
	RoqmeDDSTopics::RoqmeEstimate estimate_data;
	RoqmeDDSTopics::RoqmeObservation observation_data;


	roqmeManager.createEventContextWriter();
	roqmeManager.createIntContextWriter();
	roqmeManager.createUIntContextWriter();
	roqmeManager.createDoubleContextWriter();
	roqmeManager.createBoolContextWriter();
	roqmeManager.createEnumContextWriter();
	roqmeManager.createEstimateWriter();
	roqmeManager.createObservationWriter();

	do

	{

		cin.clear();

		cout << "Publisher DDS" << endl;

		cout << "-----------" << endl
			 << endl;

		cout << "Pulsa 1 para mandar un Evento" << endl;

		cout << "Pulsa 2 para mandar un Entero" << endl;

		cout << "Pulsa 3 para mandar un Entero sin Signo" << endl;

		cout << "Pulsa 4 para mandar un Double" << endl;

		cout << "Pulsa 5 para mandar un Boolean" << endl;

		cout << "Pulsa 6 para mandar un Enumerado" << endl;

		cout << "Pulsa 7 para mandar una Estimacion" << endl;

		cout << "Pulsa 8 para mandar una Observacion" << endl;

		cout << "Elije una opcion: ";

		cin >> option;

		switch (option)

		{

		case '1':

			cout << "Introduce el nombre del Evento" << endl;
			cin >> nameContext;
			event_data.name(nameContext);
			roqmeManager.write(event_data);

			break;

		case '2':

			cout << "Introduce el nombre del Entero" << endl;
			cin >> nameContext;
			int_data.name(nameContext);
			cout << "Introduce el valor del Entero" << endl;
			cin >> int_val;
			int_data.value() = {int_val};
			roqmeManager.write(int_data);

			break;

		case '3':

			cout << "Introduce el nombre del Entero sin signo" << endl;
			cin >> nameContext;
			int_data.name(nameContext);
			cout << "Introduce el valor del Entero" << endl;
			cin >> uint_val;
			int_data.value() = {uint_val};
			roqmeManager.write(int_data);
			break;

		case '4':

			cout << "Introduce el nombre del Double" << endl;
			cin >> nameContext;
			double_data.name(nameContext);
			cout << "Introduce el valor del double" << endl;
			cin >> double_val;
			//int v= stoi(int_val);
			double_data.value() = {double_val};
			roqmeManager.write(double_data);
			break;

		case '5':
			cout << "Introduce el nombre del Bool" << endl;
			cin >> nameContext;
			bool_data.name(nameContext);
			cout << "Introduce el valor del bool" << endl;
			cin >> bool_val;
			//int v= stoi(int_val);
			bool_data.value() = {bool_val};
			roqmeManager.write(bool_data);
			break;

		case '6':

			cout << "Introduce el nombre del Enumerado" << endl;
			cin >> nameContext;
			enum_data.name(nameContext);
			cout << "Introduce el valor del enumerado" << endl;
			cin >> enum_val;
			//int v= stoi(int_val);
			enum_data.value() = {enum_val + "." + nameContext};
			roqmeManager.write(enum_data);

			break;

		case '7':

			cout << "Introduce el nombre de la estimacion" << endl;
			cin >> nameContext;
			estimate_data.name(nameContext);
			cout << "Introduce el valor del double" << endl;
			cin >> estimate_val;
			estimate_data.value() = {estimate_val};
			roqmeManager.write(estimate_data);

			break;

		case '8':

			cout << "Introduce el nombre de la observacion" << endl;
			cin >> obs_val;
			observation_data.name(obs_val);
			roqmeManager.write(observation_data);

			break;

		default:
			cout << "Adios!" << endl;

			exit = true;

			break;
		}

	} while (exit != true);

	return 0;
}
