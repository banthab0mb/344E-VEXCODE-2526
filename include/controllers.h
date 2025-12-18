#pragma once

void curvatureDrive(double forward, double curvature);
void updateCurvatureDrive();

void exponential();

std::pair<double, double> cheesyDrive(double ithrottle, double iturn);
void cheesy();