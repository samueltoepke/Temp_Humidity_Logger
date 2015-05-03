% Samuel Lee Toepke
% samueltoepke@gmail.com
% Spring 2015
% plot_results.m: Takes a tab delimited file, and plots the results in
%   either Octave or MATLAB. First column is time, second column is
%   temperature (F) and third column is humidity (%).
%
% Can be run from command line with "$ octave --persist plot_results.m".
% Make sure log_file.txt is in the same directory.

% Cleanup from possible previous runs.
close all;
clear all;

% Read from the tab delimited file.
readings = dlmread('LOG_FILE.TXT', '\t', 1, 0); 

% Create the plot.
plot(readings(:,1), readings(:,2), readings(:,1), readings(:,3)); 

% Format the plot.
axis([0 inf 0 115]); % Set origin to be bottom left.
title('Plot of Environmental Readings Over Time'); % Set title.
xlabel('Time (milliseconds)') % Set x-axis label.
ylabel('Temp (F) and Humidity (%)') % Set y-axis label.
legend('Temperature (F)','Humidity (%)') % Set a legend.
