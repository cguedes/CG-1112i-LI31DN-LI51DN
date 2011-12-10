package cg.algorithms.polygon;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.IRasterDevice;
import cg.algorithms.triangle.TriangleAlgorithmChooser;

public class ConcavePolygonFillAlgorithm implements IPolygonFillAlgorithm
{

	public void fillPolygon(IRasterDevice dc, Point[] points, Color[] colors) 
	{
		// A implementar
		
		// Exemplo de desenho de um triângulo
		//* 
		TriangleAlgorithmChooser.getDefaultAlgorithm().fillTriangle(
				dc, 
				points[0], points[1], points[2], 
				colors[0], colors[1], colors[2]
		);
		// */
		
	}
	

}
