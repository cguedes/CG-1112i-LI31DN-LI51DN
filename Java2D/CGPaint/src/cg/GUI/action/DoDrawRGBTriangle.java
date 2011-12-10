package cg.GUI.action;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.CGPaint;
import cg.GUI.IRasterDevice;
import cg.algorithms.triangle.TriangleAlgorithmChooser;


/*
 * Esta classe precisa das coordenadas de três pontos para 
 *  desenhar o triângulo.
 * Os pontos estão relacionados com as cores da seguinte forma:
 *   - 1º ponto: RED
 *   - 2º ponto: GREEN
 *   - 3º ponto: BLUE
 */
public class DoDrawRGBTriangle extends PerformNPointsAction {

	// Este comando precisa de 3 pontos
	public DoDrawRGBTriangle() { super(3); }
	
	public void doAction(CGPaint cg, Point[] points) {

		IRasterDevice dc = cg.getRasterDisplay();
		
		Color[] colors = new Color[3];
		colors[0] = Color.RED;
		colors[1] = Color.GREEN;
		colors[2] = Color.BLUE;

		// RGB
		dc.writePixel(points[0].x, points[0].y, colors[0]);
		dc.writePixel(points[1].x, points[1].y, colors[1]);
		dc.writePixel(points[2].x, points[2].y, colors[2]);
		
		// Debug
		Point r = points[0];
		Point g = points[1];
		Point b = points[2];
		dc.addLine(r, g);
		dc.addLine(g, b);
		dc.addLine(b, r);

		// Process default triangle fill algorithm
		TriangleAlgorithmChooser.getDefaultAlgorithm().fillTriangle(dc, r, g, b, colors[0], colors[1], colors[2]);

	}
	
	public void drawAction(CGPaint cg, Point[] points, int nPoints, Point mousePos){
		if(nPoints >= 1) {
			Point[] _points = new Point[nPoints+1];
			for(int i = 0; i < nPoints; ++i) {
				_points[i] = points[i];
			}
			_points[nPoints] = new Point(mousePos);
			cg.drawInfoLines(_points, _points.length);
		}
	}	
}
