/**
 * 
 */
package cg.GUI;

import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionAdapter;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

import javax.swing.JPanel;

/**
 * @author cguedes
 *
 */
public class GridView extends JPanel implements IRasterDevice {

	private static final long serialVersionUID = 6797071580228859584L;
	
	/**
	 */
	private int ncols;
	/**
	 */
	private int nlines;
	/**
	 */
	private int gridStep = 1;
	
	private BufferedImage sceneImage = null;
	private boolean isSceneValid = false;

	// info 
	private ArrayList<Point> infoPoints = new ArrayList<Point>();
	private int infoType = -1;
	
	// DEBUG: Linhas e circulos a desenhar
	private class LineInfo {
		public Point start;
		public Point end;
		public LineInfo(Point _start, Point _end) { start = _start; end = _end; }
	}
	private class CircleInfo {
		public Point center;
		public int radius;
		public CircleInfo(Point _center, int _radius) { center = _center; radius = _radius; }
	}
	/**
	 */
	private ArrayList<LineInfo> lines = new ArrayList<LineInfo>();
	/**
	 */
	private ArrayList<CircleInfo> circles = new ArrayList<CircleInfo>();

	// Pontos a desenhar
	private ArrayList<PointRGB> points = new ArrayList<PointRGB>();
	
	/**
	 * Cria uma grelha de @param nlines linhas por @param ncols colunas. 
	 * 
	 * @param nlines
	 * @param ncols
	 */
	public GridView(int nlines, int ncols) {
		this.ncols = ncols;
		this.nlines = nlines;
		this.setBackground(Color.WHITE);
		setupEvents();
	}
	
	/* ************************************************************************
	 * PAINT
	 ************************************************************************ */

	/**
	 * Desenhar a cena de acordo com a informação de pontos e linhas existentes
	 *   - A informação de linhas apenas é desenhada se estivermos em modo "DEBUG"
	 */
	public void paint(Graphics gPaint) {
		super.paint(gPaint);
		
		int stepX = getWidth() / ncols;
		int stepY = getHeight() / nlines;
		gridStep = Math.min(stepX, stepY);

		// Gerar a imagem da cena, se esta estiver inválida
		if( !isSceneValid ) {
			sceneImage = new BufferedImage(this.getWidth(), this.getHeight(), BufferedImage.TYPE_INT_ARGB);
			Graphics g = sceneImage.getGraphics();

			// Desenhar a grelha
			if(isInDebugMode()) {
				
				int gridSize = 2;
				int gridSizeDiv2 = gridSize / 2;
				g.setColor(Color.BLACK);
				for (int y = gridStep; y < getHeight(); y+=gridStep) {
					for (int x = gridStep; x < getWidth(); x+=gridStep) {
						//g.drawLine(x, y, x, y);
						g.fillOval(x-gridSizeDiv2, y-gridSizeDiv2, gridSize, gridSize);
					}
				}
			}
			
			// Desenhar o EIXO de COORDENADAS
			g.setColor(Color.RED);
			Point axisCenter = translate(0, 0);
			Point axisX = translate(1, 0);
			g.drawLine(axisCenter.x, axisCenter.y, axisX.x, axisX.y);
			g.drawString("X", axisX.x, axisX.y);
			g.setColor(Color.GREEN);
			Point axisY = translate(0, 1); 
			g.drawLine(axisCenter.x, axisCenter.y, axisY.x, axisY.y);
			g.drawString("Y", axisY.x, axisY.y);
		
			// Desenhar os pontos
			int pointSize = gridStep - gridStep / 4;
			for (int i = 0; i < points.size(); i++) {
				PointRGB prgb = points.get(i);
				Point p = translate(prgb.x, prgb.y);
				g.setColor(prgb.color);
				g.fillOval(p.x-pointSize/2, p.y-pointSize/2, pointSize, pointSize);						
			}

			if(isInDebugMode()) {
				
				// Desenhar as linhas (pares de dois pontos no contentor lines)
				g.setColor(Color.GREEN);
				for(int i = 0; i < lines.size(); ++i) {
					LineInfo li = lines.get(i);
					Point p1 = translate(li.start);
					Point p2 = translate(li.end);
					g.drawLine(p1.x, p1.y, p2.x, p2.y);
				}
				// Desenhar os circulos
				g.setColor(Color.GREEN);
				for(int i = 0; i < circles.size(); ++i) {
					CircleInfo ci = circles.get(i);
					Point p = translate(ci.center);
					int r = ci.radius * gridStep * 2;
					g.fillOval(p.x-pointSize/4, p.y-pointSize/4, pointSize/2, pointSize/2);
					g.drawOval(p.x - r / 2, p.y - r / 2, r, r);
				}
			}
			
			// Desenhar informacao da construcao de primitivas
			if(infoType == 0){
				g.setColor(Color.GREEN);
				for(int i=0; i<infoPoints.size()-1; ++i){
					g.drawLine(infoPoints.get(i).x, infoPoints.get(i).y, infoPoints.get(i+1).x, infoPoints.get(i+1).y);
				}
			}
			else if(infoType == 1){
				g.setColor(Color.GREEN);
				Point a = infoPoints.get(0);
				Point b = infoPoints.get(1);
				int d = (int)Math.sqrt((b.x-a.x)*(b.x-a.x) +  (b.y-a.y)*(b.y-a.y));
				g.drawOval(infoPoints.get(0).x - d, infoPoints.get(0).y - d, d*2, d*2);
			}
			else if(infoType == 2){
				g.setColor(Color.GREEN);
				Point a = infoPoints.get(0);
				Point b = infoPoints.get(1);
				int w = Math.abs(a.x-b.x);
				int h = Math.abs(a.y-b.y);
				g.drawRect(Math.min(a.x, b.x), Math.min(a.y,b.y), w, h);
			}
			isSceneValid = true;

		} // if(!isSceneValid)
		
		// Desenhar a cena (imagem)
		gPaint.drawImage(sceneImage, 0, 0, getWidth(), getHeight(), this);
		
		gPaint.setColor(Color.BLACK);
		gPaint.drawString(strToShow, 10, 20);

	}
	
	private Point translate(int x, int y) {
		Point p = new Point(x, y);
		p.x *= gridStep;
		p.y *= gridStep;

		p.y *= -1;

		p.x += gridStep;
		p.y += gridStep * nlines;  
		
		return p;
	}
	
	private Point translate(Point p) {
		return translate(p.x,p.y) ;
	}
	
	private Point translateInverse(int x, int y) {

		double gridStepDiv2 = gridStep / 2;
		double xx = (x-gridStepDiv2) / gridStep;
		double yy = (y-gridStepDiv2) / gridStep;
		
		yy *= -1;
		yy += nlines;
		
		Point p = new Point(x, y);
		p.x = (int)xx;
		p.y = (int)yy;

		return p;
	}
	
	private Point translateInverse(Point p) {
		return translateInverse(p.x,p.y) ;
	}

	/* ************************************************************************
	 * Raster 2D
	 ************************************************************************ */
	public void writePixel(int x, int y, Color color) {
		points.add(new PointRGB(x, y, color));
		invalidateScreenData();
	}

	public void clear() {
		points.clear();
		lines.clear();
		circles.clear();
		invalidateScreenData();
	}
	
	/* ************************************************************************
	 * Integração com o JAVA
	 ************************************************************************ */
	public Component getComponent() {
		return this;
	}

	/* ************************************************************************
	 * Debug
	 ************************************************************************ */
	/**
	 */
	private boolean debugOn = false;
	public void setDebugMode(boolean isDebugOn) {
		debugOn = isDebugOn;
		invalidateScreenData();
	}
	public boolean isInDebugMode() { return debugOn; }

	/**
	 * Indica que a linha que liga os pontos p1 a p2 deve ser desenhada.
	 * Esta linha é desenhada de forma "discreta" - sem ser pixel a pixel. 
	 */
	public void addLine(Point p1, Point p2) {
		lines.add(new LineInfo(p1, p2));
		invalidateScreenData();
	}
	public void addCircle(Point p1, int radius) {
		circles.add(new CircleInfo(p1, radius));
		invalidateScreenData();
	}
	public void incGridSize() {
		nlines += 4;
		ncols += 4;
		invalidateScreenData();
	}
	public void decGridSize() {
		nlines -= 4;
		ncols -= 4;
		invalidateScreenData();
	}
	
	public void invalidateScreenData() {
		isSceneValid = false;
	}
	
	public void drawStatusString(String str) {
		strToShow = str;
	}
	
	/* ************************************************************************
	 * Geração de eventos
	 ************************************************************************ */
	private void setupEvents() {
		// Mouse Listener
		this.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent me) {
				mListener.mouseClicked(getTranslatedMouseEvent(me));
			}
		});
		// Mouse Motion Listener
		this.addMouseMotionListener(new MouseMotionAdapter() {
			public void mouseMoved(MouseEvent me) {
				mmListener.mouseMoved(getTranslatedMouseEvent(me));
			}
			public void mouseDragged(MouseEvent me) {
				mmListener.mouseDragged(getTranslatedMouseEvent(me));
			}
		});
	}
	
	private MouseEvent getTranslatedMouseEvent(MouseEvent me) {
		Point p = me.getPoint();
		p = translateInverse(p);
		MouseEvent newMouseEvent = new MouseEvent( (Component)me.getSource(), me.getID(), me.getWhen(), me.getModifiers(), p.x, p.y, me.getClickCount(), me.isPopupTrigger(), me.getButton());
		return newMouseEvent;
	}
	
	/**
	 */
	private MouseListener mListener = null;
	public void addClickListener(MouseListener ml) {
		if(mListener != null) 
			throw new IllegalArgumentException("Apenas é suportado um mouse mListener!");
		mListener = ml;
	}
	
	/**
	 */
	private MouseMotionListener mmListener = null;

	private String strToShow = "";

	public void addMotionListener(MouseMotionListener mml) {
		if(mmListener != null) 
			throw new IllegalArgumentException("Apenas é suportado um mouse motion mListener!");
		mmListener = mml;
	}
	
	public void drawInfoLines(Point p[], int nPoints){
		infoPoints.clear();
		infoType = 0;
		for(int i=0; i<nPoints; ++i){
			infoPoints.add(translate(p[i]));
		}
	}
	
	public void drawInfoCircle(Point c, Point r){
		infoPoints.clear();
		infoType = 1;
		infoPoints.add(translate(c));
		infoPoints.add(translate(r));
	}
	
	public void drawInfoRectgangle(Point a, Point b){
		infoPoints.clear();
		infoType = 2;
		infoPoints.add(translate(a));
		infoPoints.add(translate(b));
	}
	
	public void clearInfo(){
		infoType = -1;
	}
}
