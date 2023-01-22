// so asa graph cha shubharambh hot ahe

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int destinationVertexID;
    int weight;

    Edge()
    {
    }
    Edge(int d, int w)
    {
        destinationVertexID = d;
        weight = w;
    }
    void setDestinationVertexID(int d)
    {
        destinationVertexID = d;
    }
    void setWeight(int w)
    {
        weight = w;
    }
    int getDestinationVertexID()
    {
        return destinationVertexID;
    }
    int getWeight()
    {
        return weight;
    }
};

class Vertex
{
public:
    int state_ID;
    string state_name;
    list<Edge> edgeList;

    Vertex()
    {
        state_ID = 0;
        state_name = "";
    }
    Vertex(int id, string s)
    {
        state_ID = id;
        state_name = s;
    }
    void setStateID(int s)
    {
        state_ID = s;
    }
    void setStateName(string s)
    {
        state_name = s;
    }
    int getStateId()
    {
        return state_ID;
    }
    string getStateName()
    {
        return state_name;
    }
    list<Edge> getEdgeList()
    {
        return edgeList;
    }
};

class Graph
{
public:
    vector<Vertex> vertices;

    // facilitators
    bool isVertexExistByID(int vid)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].getStateId() == vid)

                return true;
        }
        return false;
    }

    auto getVertexByID(int id)
    {
        Vertex temp;
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].state_ID == id)
            {
                temp = vertices[i];
                break;
            }
        }
        return temp;
    }

    bool isEdgeExistByID(int id1, int id2)
    {
        Vertex v = getVertexByID(id1);
        auto temp = v.getEdgeList();
        for (auto it : temp)
        {
            if (it.destinationVertexID == id2)
                return true;
        }
        return false;
    }

    // Graph Operations
    void addVertex(int id, string name)
    {
        bool check = isVertexExistByID(id);
        if (check)
            cout << "\nVertex with this ID already Exists ";
        else
        {
            Vertex v(id, name);
            vertices.push_back(v);
            cout << "\nVertex Added Successfully!";
        }
    }

    void addEdge(int id1, int id2, int wt)
    {
        bool check1 = isVertexExistByID(id1);
        if (!check1)
        {
            cout << "\nVertex with ID : " << id1 << " does not exist! ";
            return;
        }
        bool check2 = isVertexExistByID(id2);
        if (!check2)
        {
            cout << "\nVertex with ID : " << id2 << " does not exist! ";
            return;
        }

        if (check1 && check2)
        {
            bool checkEdge = isEdgeExistByID(id1, id2);
            if (!checkEdge)
            {
                bool one = false, two = false;
                for (int i = 0; i < vertices.size(); i++)
                {
                    if (one && two)
                    {
                        cout << "\nEdge is Added Successfully ! ";
                        return;
                    }
                    if (vertices[i].getStateId() == id1)
                    {
                        Edge e(id2, wt);
                        vertices[i].edgeList.push_back(e);
                        one = true;
                    }
                    else if (vertices[i].getStateId() == id2)
                    {
                        Edge e(id1, wt);
                        vertices[i].edgeList.push_back(e);
                        two = true;
                    }
                }
            }
            else
            {
                cout << "\nEdge is already present between vertex " << id1 << " and " << id2;
            }
        }
    }

    void updateEdge(int id1, int id2, int wt)
    {
        bool check = isEdgeExistByID(id1, id2);
        bool one = false, two = false;
        if (check)
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices[i].getStateId() == id1)
                {
                    for (auto &it : vertices[i].edgeList)
                    {
                        if (it.getDestinationVertexID() == id2)
                        {
                            it.setWeight(wt);
                            one = true;
                            break;
                        }
                    }
                }

                else if (vertices[i].getStateId() == id2)
                {
                    for (auto &it : vertices[i].edgeList)
                    {
                        if (it.getDestinationVertexID() == id1)
                        {
                            it.setWeight(wt);
                            two = true;
                            break;
                        }
                    }
                }
                if (one && two)
                {
                    cout << "\nEdge updated successfully ";
                    return;
                }
            }
        }
        else
        {
            cout << "\nEdge is not present between vertex " << id1 << " and " << id2;
        }
    }

    void deleteEdge(int id1, int id2)
    {
        cout << id1 << ' ' << id2 << endl;
        bool check = isEdgeExistByID(id1, id2);
        bool one = false, two = false;
        if (check)
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices[i].getStateId() == id1)
                {
                    for (auto it = vertices[i].edgeList.begin(); it != vertices[i].edgeList.end(); it++)
                    {
                        if (it->getDestinationVertexID() == id2)
                        {
                            vertices[i].edgeList.erase(it);
                            one = true;
                            break;
                        }
                    }
                }
                else if (vertices[i].getStateId() == id2)
                {
                    for (auto it = vertices[i].edgeList.begin(); it != vertices[i].edgeList.end(); it++)
                    {
                        if (it->getDestinationVertexID() == id1)
                        {
                            vertices[i].edgeList.erase(it);
                            two = true;
                            break;
                        }
                    }
                }
                if (one && two)
                {
                    cout << "\nEdge removed successfully ";
                    return;
                }
            }
        }
        else
        {
            cout << "\nEdge is not present between vertex " << id1 << " and " << id2;
            return;
        }
    }

    void updateVertexByID(int id, string name)
    {
        bool check = isVertexExistByID(id);
        if (check)
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices[i].state_ID == id)
                {
                    vertices[i].setStateName(name);
                }
                cout << "\nUpdated Vertex Successfully!";
                break;
            }
        }
        else
        {
            cout << "\nVertex with id " << id << " does not exits!";
        }
    }

    void deleteVertexByID(int id)
    {
        cout << "\nenterd in delete vertex";
        int index;
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].state_ID == id)
            {
                index = i;
                break;
            }
        }

        for (int i = 0; i < vertices.size(); i++)
        {
            for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++)
            {
                if (it->getDestinationVertexID() == id)
                {
                    vertices.at(i).edgeList.erase(it);
                    break;
                }
            }
        }
        vertices.erase(vertices.begin() + index);
        cout << "\nVertex Deleted Successfully";
    }

    void printNeighbours(int id)
    {
        int index;
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].getStateId() == id)
            {
                index = i;
                break;
            }
        }
        cout << "\nThe neighbours are : ";
        for (auto it = vertices[index].edgeList.begin(); it != vertices[index].edgeList.end(); it++)
        {
            cout << "\nID : ";
            cout << it->destinationVertexID << " weight : " << it->getWeight();
        }
        cout << "\nNeighbours printed successfully";
    }

    void printEdges(list<Edge> e)
    {
        for (auto it : e)
        {
            cout << it.destinationVertexID << "(" << it.weight << ") "
                 << "--> ";
        }
    }

    void printGraph()
    {
        cout << "\nvertices are as follow\n";
        for (int i = 0; i < vertices.size(); i++)
        {
            cout << vertices[i].getStateName() << " (" << vertices[i].getStateId() << ") -->";
            cout << " [";
            printEdges(vertices[i].edgeList);
            cout << "]";
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    string name;
    int id, id1, id2, wt;

    int repeat = 1;
    do
    {
        cout << "\n\nSelect Option : ";
        cout << "\n1.Add Vertex"
             << "\n2.Update Vertex "
             << "\n3.Delete Vertex"
             << "\n4.Add Edge "
             << "\n5.Update Edge"
             << "\n6.Delete Edge"
             << "\n7.Check Neighbours"
             << "\n8.Print all neighbours"
             << "\n9.Print Graph"
             << "\n10.Clear Screen"
             << "\n0.Exit Program"
             << "\nyou chose : ";

        int c;
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "\n1.Add vertex operation ";
            cout << "\nEnter the ID of the vertex : ";
            cin >> id;
            cout << "\nEnter the Name of the Vertex : ";
            cin >> name;

            g.addVertex(id, name);

            break;
        case 2:
            cout << "\n2.Update vertex ";
            cout << "\nEnter the ID of the vertex : ";
            cin >> id;
            cout << "\nEnter the name of Vertex : ";
            cin >> name;
            g.updateVertexByID(id, name);
            break;

        case 3:
            cout << "\n3.Delete Vertex ";
            cout << "\nEnter the ID of Vertex : ";
            cin >> id;
            g.deleteVertexByID(id);
            cout << "\nafter delete in main:  ";
            break;

        case 4:
            cout << "\n4.Add Edge ";
            cout << "\nEnter the source vertex ID : ";
            cin >> id1;
            cout << "\nEnter the destination vertes ID : ";
            cin >> id2;
            cout << "\nEnter the weight of the Edge : ";
            cin >> wt;
            g.addEdge(id1, id2, wt);
            break;

        case 5:
            cout << "\n5.Update Edge";
            cout << "\nEnter the source vertex ID : ";
            cin >> id1;
            cout << "\nEnter the destination vertes ID : ";
            cin >> id2;
            cout << "\nEnter the new weight of the Edge : ";
            cin >> wt;
            g.updateEdge(id1, id2, wt);
            break;

        case 6:
            cout << "\n6.Delete Edge ";
            cout << "\nEnter the source vertex ID : ";
            cin >> id1;
            cout << "\nEnter the destination vertes ID : ";
            cin >> id2;
            g.deleteEdge(id1, id2);
            break;

        case 7:
            cout << "7.check neighbours ";
            break;

        case 8:
            cout << "\n8.Print all neighbours";
            cout << "\nEnter the vertex id : ";
            cin >> id;
            g.printNeighbours(id);
            break;

        case 9:
            cout << "Print Graph";
            g.printGraph();
            break;

        case 0:
            repeat = 0;
            break;

        default:
            break;
        }

    } while (repeat);

    return 0;
}