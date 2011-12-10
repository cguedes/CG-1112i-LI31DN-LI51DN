package cg.GUI.action;

import java.awt.Color;
import java.awt.Point;


import cg.GUI.CGPaint;
import cg.GUI.IRasterDevice;
import cg.algorithms.line.IScanLineAlgorithm;

public class DoRectangle extends PerformNPointsAction {

	// Este comando precisa de 2 pontos
	public DoRectangle() { super(2); }

	public void doAction(CGPaint cg, Point[] points)
	{
		Point start = points[0];
		Point end = points[1];
		
		IRasterDevice dc = cg.getRasterDisplay();
		Point p2 = new Point(start.x, end.y);
		Point p4 = new Point(end.x, start.y);
		
		Color color = cg.getCurrentColor();		
		IScanLineAlgorithm alg=cg.getCurrentLineAlgorithm();
		alg.drawLine(dc, start, p2,color);
		alg.drawLine(dc, p2, end, color);
		alg.drawLine(dc, end, p4, color);
		alg.drawLine(dc, p4, start, color);
		
		dc.addLine(start, end);		

	}
	public void drawAction(CGPaint cg, Point[] points, int nPoints, Point mousePos){
		if(nPoints == 1){
			cg.drawInfoRectgangle(points[0], mousePos);
		}
	}	
}
