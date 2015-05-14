											#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define SQL_DEBUG 1
#define DEBUG 0
// Standard Qt Includes
#include <QMainWindow>
#include <QDebug>
#include <QFont>
#include <QFile>
#include <QApplication>
#include <QtGui>
#include <QMessageBox>

// Qt Sql includes, database, query and table display
#include <QTableView>
#include <QSqlQueryModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QAbstractItemView>
#include <QAbstractItemModel>

// Project includes
#include "graph.h"
#include "stadium.h"
#include "MainHeader.h"
//#include "hashTable.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		bool createConnection(bool restart = false);
		void showTableView();
		void fillGraph();

		void refresh();
		bool setState(int stadiumId, const QString &state);
		bool setTeamName(int stadiumId, const QString &teamName);
		bool setSurface(int stadiumId, const QString &playingSurface);
		bool setCity(int stadiumId, const QString &city);
		bool setStadiumName(); // <----- EXAMPLE & Demo for functionality
		bool setStadiumName(int stadiumId,const QString &teamName);

		void initializeModel(QSqlTableModel *initModel, bool editField = true);
        void initializeSouvenir(QSqlTableModel *initModel, bool editField = true);

		QTableView* createView(QSqlTableModel *initModel, const QString &title);
		// This method will take a model foo and give it a title foobar.
		//	MAKE SURE TO DEALLOCATE MEMORY for model foo



        stadium searchForStadium(string searchKey);



		bool setStreet(int stadiumId, const QString& street);
		void submit(QSqlTableModel* model);
		bool addStadium(stadium stadiumData);

        void SetProgressBar(int location);

        void initializeShoppingCart(QSqlTableModel *cartModel, bool editField);

	private slots:
		void on_button_back0_clicked();

		void on_button_planATrip0_clicked();

		void on_button_searchForStadiums0_clicked();

		void on_button_mainMenu0_clicked();

		void on_button_back1_clicked();

		void on_button_mainMenu1_clicked();

		void on_button_mainMenu2_clicked();

		void on_button_back2_clicked();

		void on_button_mainMenu3_clicked();

		void on_button_back3_clicked();

		void on_button_mainMenu4_clicked();

		void on_button_back4_clicked();

		void on_button_viewStadiums_clicked();

		void on_button_shop0_clicked();

		void on_button_adminAccess0_clicked();

		void on_button_mainMenu5_clicked();

		void on_button_login_clicked();

		void on_button_back_adminMainMenu_clicked();

		void on_button_continueAddStadium_clicked();

		void on_button_backAddStadium_clicked();

		void on_button_addStadium0_clicked();

        void on_button_quickTrip0_clicked();

        void on_button_confirm_clicked();

        void on_button_cancel_clicked();

        void on_button_finish_clicked();

        void on_button_customTrip0_clicked();

        void on_pushButton_customTripGo_clicked();

        void on_button_customTripBack_clicked();

        void on_button_customTripMainMenu_clicked();

        void on_button_customTripBack_2_clicked();

        void on_button_customTripMainMenu_2_clicked();

        void on_pushButton_customTripNext_clicked();

        void on_pushButton_customTripPrevious_clicked();

        void on_button_quickTripBack_clicked();

        void on_button_quickTripMainMenu_clicked();

        void on_pushButton_quickTripGo_clicked();

        void on_button_MST_clicked();

        void on_button_backMST_clicked();

        void on_button_backMainMenuMST_clicked();

private:
		Ui::MainWindow *ui;
		QSqlDatabase db;
		QTableView* viewModel;
        QSqlTableModel* souvenirModel;
        QSqlTableModel* initModel;
        QSqlTableModel* cartModel;
        /*
		 * Vertex: stadium
		 * Edge: float (could be int, but let's make it generic)
		 */
		Graph<stadium,float> graph;
        QMap<QString,stadium> stadiumHash;
        QMap<QString,stadium>::iterator stadiumIt;

        // used to store most recent graph algorithm (global to this class)
        // mst      --> need edges
        // dijkstra --> need vertices
        vector<Edge<stadium,float> *> mstEdgeVector;
        vector<Vertex<stadium> *> dijkstraVertexVector;

        int currentStadiumIndex;
        bool quickTrip;

};

#endif // MAINWINDOW_H
