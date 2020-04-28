clear
clc
close

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
linkedlistdataSetA = readtable("C:\Users\Brian's Laptop\OneDrive\Documents\CSCI 2270\Final Project\insert_search_performance_linked_list_dataSetA.csv", opts);


for R = 1:400
      Insert(R) = linkedlistdataSetA{R,1};
      Search(R) = linkedlistdataSetA{R,2};
end 

figure()
hold on
plot(Insert)
plot(Search)

xlabel('Iterations');
ylabel('Time');
title('Linked List - Dataset A');
legend('Insert', 'Search');
hold off
