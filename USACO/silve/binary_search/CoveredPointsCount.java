import javax.swing.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;



public class CoveredPointsCount {
     static class Pair{
        public long first;
        public long second;
        public Pair(long first,long second)
        {
            this.first=first;
            this.second=second;
        }

    }
    public static void main(String[] args) throws IOException {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int n=Integer.parseInt(in.readLine());
        CoveredPointsCount.Pair[] segment=new CoveredPointsCount.Pair[n];

        SortedSet<Long> Points=new TreeSet<>();
        for(int i=0;i<n;i++)
        {
            StringTokenizer st=new StringTokenizer(in.readLine());
            segment[i]=new Pair(Long.parseLong(st.nextToken()),Long.parseLong(st.nextToken()));

            Points.add(segment[i].first);Points.add(segment[i].second+1);
        }

        in.close();
        int cur=0;
        Map<Long,Integer> compressed=new HashMap<>();

        List<Long> coords=new ArrayList<>();
        for( var i:Points)
        {
            compressed.put(i,cur);
            coords.add(i);
            cur++;
        }

        int[] fre=new int [2*n];
        for(int i=0;i<n;i++)
        {
            fre[compressed.get(segment[i].first)]++;
            fre[compressed.get(segment[i].second+1)]--;
        }
        for(int i=1;i<2*n;i++) fre[i]+=fre[i-1];

        long[] coveredNum=new long[n+1];
        for(int i=1;i<coords.size();i++)
        {
            coveredNum[fre[i-1]]+= coords.get(i) - coords.get(i-1);
        }
        for(int i=1;i<=n;i++)
        {
            out.print(coveredNum[i]+" ");
            out.flush();
        }



    }
}