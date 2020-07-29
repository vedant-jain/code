class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_set<int>visited;
       for(int i=0;i<queries.size();i++) //iterating through all the queries
       {
           ans.push_back(help(equations,values,queries[i][0],queries[i][1],visited));
       }
        return ans;
    }
    // this function search for the asked numerator and denominator pair value stored as
	// num and  den
	//visited set is keep record of visited equations by storing their index's
	
    double help(vector<vector<string>>& equations, vector<double>& values,string num,string den,unordered_set<int>visited)
    {
     //cout<<num<<" "<<den<<"\n";
         
        
            if(num==den){  // when num is equal to den we also need to check if it exists in equations or not
                for(int j=0;j<equations.size();j++)
                {
                    if(equations[j][0]==num || equations[j][1]==den)
                    {
                        return 1.0;
                    }
                }
                return -1.0;
            }
            else   // this else loop to check for the reciprocals of a pair
            {
                
                for(int j=0;j<equations.size();j++)
                {
                    if(equations[j][0]==num && equations[j][1]==den)
                    {
                        return values[j];
                        
                    }
                    else if(equations[j][0]==den && equations[j][1]==num)
                    {
                        return 1/values[j];
                    
                    }
                }
                
            }
        //we come in this portion when we don't have a query like (a/a) or  (a/b),given(b/a)
		
        for(int i=0;i<equations.size();i++)
        {
           
            if(visited.find(i)==visited.end() && (equations[i][0]==num || equations[i][1]==num))
             {
                visited.insert(i);
                for(int j=0;j<equations.size();j++)
                {
                    if( visited.find(j)==visited.end() && (equations[j][0]==den || equations[j][1]==den)){
                        visited.insert(j);
                        string newnum,newden;
                        int pow_num=1,pow_den=1;
                        if(equations[i][0]==num ){newnum=equations[i][1];}
                        else{newnum=equations[i][0]; pow_num=-1;}
                        if(equations[j][0]==den ){newden=equations[j][1];pow_den=-1;}
                        else{newden=equations[j][0];}
                        
 
                        
                        double x=help(equations,values,newnum,newden,visited);
                       if( x!=-1.0)
                       {
                           return x*pow(values[i],pow_num)*pow(values[j],pow_den);
                       }
                        
                       visited.erase(visited.find(j)); 
                    }
                }
                 visited.erase(visited.find(i)); 
             }
            
        }
       
    return -1.0;
    
    
    }
};