package com.MyWC;

import java.io.IOException;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class WCMapper extends Mapper<LongWritable, Text, Text, IntWritable>{

    @Override
    protected void map(LongWritable key1, Text value1, Context context)
            throws IOException, InterruptedException {

        //数据： I like MapReduce
        String data = value1.toString();

        //分词：按空格来分词
        String[] words = data.split(" ");

        //输出 k2    v2
        for(String w:words){
            context.write(new Text(w), new IntWritable(1));
        }
    }

}