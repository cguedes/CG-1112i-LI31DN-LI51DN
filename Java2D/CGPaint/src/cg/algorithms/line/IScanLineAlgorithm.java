package cg.algorithms.line;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.IRasterDevice;

public interface IScanLineAlgorithm {

	void drawLine(IRasterDevice dc, Point start, Point end);
	void drawLine(IRasterDevice dc, Point start, Point end, Color color);
	
}
