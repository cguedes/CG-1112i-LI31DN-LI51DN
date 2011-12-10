package cg.algorithms.triangle;

import java.util.Dictionary;
import java.util.Enumeration;
import java.util.Hashtable;


public final class TriangleAlgorithmChooser {

	private static Dictionary<String, ITriangleFillAlgorithm> algorithms = new Hashtable<String, ITriangleFillAlgorithm>();
	
	static {		
		algorithms.put("TriangleFillGouraud", new TriangleFillAlgorithm());
	}
	
	public static Enumeration<String> getAvailableAlgorithms() {
		return algorithms.keys();
	}
	
	public static ITriangleFillAlgorithm getAlgorithm(String algName) {
		return algorithms.get(algName);
	}
	
	public static ITriangleFillAlgorithm getDefaultAlgorithm() {
		return algorithms.get(algorithms.keys().nextElement());
	}
	
	
	
}
