//////////////////
// MS SQL Server
/////////////////////////////////////////////////
// docker pull microsoft/mssql-server-linux
//////////////////////////////////////////////////////////////Host:Cont////
// docker run -e 'ACCEPT_EULA=Y' -e 'SA_PASSWORD=HugoEgon' -p 1433:1433 -d microsoft/mssql-server-linux:2017-latest
/////////////
// Starten einer Shell im Container
//////////
// docker exec -it dc246cf4dd8d "bash"
////////////////////////
// Anmelden am Server
////////////////////////
// /opt/mssql-tools/bin/sqlcmd -S localhost -U SA -P 'Hugo/Egon'

/////////////////////////////////////////////////
// liquibase
/////////////
// docker pull webdevops/liquibase

///////////////////////////////////////////////
// Schemas ..
////////////
// What is a database schema
//////////
// schema : database : table : floor plan : house : room
//////////
// https://stackoverflow.com/questions/298739/what-is-the-difference-between-a-schema-and-a-table-and-a-database
////////////////////////////////////
// Set the schema of a data base
//////////
// https://stackoverflow.com/questions/8208019/how-to-set-the-default-schema-of-a-database-in-sql-server-2005
/////////////////////////////////
// Unknown connection error
/////////////////////////////////
// https://bugs.eclipse.org/bugs/show_bug.cgi?id=298730
//////////
Your screenshots show that you are using the jtds JDBC driver, but using the Microsoft SQL Server specific driver definition. The automatically formatted connection URL (jdbc:sqlserver://shanghai:1433;databaseName=test) is specific to sqljdbc, and thus not valid for the jtds JDBC driver.

If you want to use the jtds JDBC driver, select the "Generic JDBC" type instead.  Using its corresponding UI, you can input your own connection URL specific for jtds, e.g. jdbc:jtds:sqlserver://shanghai:1433/test .

//////////////////////////////////////////////
// Aufsetzen der Eclipse IDE und Verknüpfen mit MS SQL Server
/////////
// Download der Treiber
/////////
// https://www.microsoft.com/en-us/download/details.aspx?id=11774
/////////
// Aufpassen mit der Namenskonvention der Treiber ab MS SQL Server 2005
// Die Namenskonvention der URL hat sich geändert:
// + URL bis Server 2000 - com.microsoft.jdbc.sqlserver.SQLServerDriver
// + URL ab Server 2005 - com.microsoft.sqlserver.jdbc.SQLServerDriver
/////////
// Anpassen der CLASSPATH Variable
// Dies ist notwendig, da Eclipse die Treiber sonst nicht findet.
// Die Treiber sind nicht Bestandteile der Standard Pakete und müssen explizit hinzugefügt werden.
/////////
// echo $CLASSPATH
// CLASSPATH=/home/hofmanma/Dokumente/MSSQL/sqljdbc_6.4/enu/mssql-jdbc-6.4.0.jre7.jar
/////////////////////////////
// Hinzufügen des MS SQL jdbc Treibers zu Eclipse:
// 1. Right-click on your project root node, 
// 2. select Properties, 
// 3. go to Java Build Path, 
// 4. select Libraries tab, 
// 5. and Add External JARs. 

/////////////////////////////
// Git in Eclipse
//////////////////
// http://www.vogella.com/tutorials/EclipseGit/article.html
// http://www.vogella.com/tutorials/EclipseGit/article.html#eclipsegit_userconfiguration
//////////////////
// Install - http://download.eclipse.org/egit/updates

///////////////////////////////////////
// Proxy setting in Eclipse
// In a recent version of eclipse :
//------------------------------------
//  Go to Window -> Preferences -> General -> Network Connections=
//  Change the provider to "Manual"
//  Select the "HTTP" line and click the edit button.
//  Add the IP address and port number above to the http line.
//  If you have to authenticate to use the proxy, ...
//  Click OK.
//  Click Apply.
//  Click OK.
