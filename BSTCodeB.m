clear
clc
close
%% Setup the Import Options
opts = delimitedTextImportOptions("NumVariables", 2);

% Specify range and delimiter
opts.DataLines = [1, Inf];
opts.Delimiter = ",";

% Specify column names and types
opts.VariableNames = ["e05", "e1"];
opts.VariableTypes = ["double", "double"];
opts.ExtraColumnsRule = "ignore";
opts.EmptyLineRule = "read";

% Import the data
BSTdataSetB = readtable("C:\Users\Brian's Laptop\OneDrive\Documents\CSCI 2270\Final Project\BST\Matlab\insert_search_performance_BST_dataSetB.csv", opts);


for R = 1:400
      Insert(R) = BSTdataSetB{R,1};
      Search(R) = BSTdataSetB{R,2};
end 

figure()
hold on
plot(Insert)
plot(Search)

xlabel('Iterations');
ylabel('Time');
title('BST - Dataset B');
legend('Insert', 'Search');
hold off
