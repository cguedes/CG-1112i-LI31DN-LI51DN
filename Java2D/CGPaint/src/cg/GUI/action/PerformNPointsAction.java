package cg.GUI.action;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.CGPaint;

/**
 * Esta classe serve de base aos comandos. 
 * É configurada para apenas chamar o doAction quando
 *   tiver lido N pontos (passados como parâmetro ao construtor).
 */
public abstract class PerformNPointsAction implements IPerformAction {

	private int nPointsReaded = 0;
	private Point[] points = null;
	
	protected PerformNPointsAction(int npoints) {
		points = new Point[npoints];
	}

	public void doAction(CGPaint cg, Point pos, Color color) {
		// Regista-se o ponto na posição actual
		points[nPointsReaded++] = pos;
		
		// Se estamos a registar o último ponto (3º), desenha-se o triângulo
		if(nPointsReaded == points.length) {
			// Desenhar o triângulo
			nPointsReaded = 0;
			doAction(cg, points);
			cg.clearInfo();
		}
	}
	
	public void drawAction(CGPaint cg, Point mousePos, Color color) {
		drawAction(cg, points, nPointsReaded, mousePos);	
	}

	protected abstract void doAction(CGPaint cg, Point[] points);
	protected abstract void drawAction(CGPaint cg, Point[] points, int nPoints, Point mousePos);	
}
