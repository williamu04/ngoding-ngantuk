import React from 'react';
import './SearchPage.css'; 
import { TuneOutlined } from '@mui/icons-material';
import ChannelRow from './ChannelRow';
import VideoRow from './VideoRow';

function SearchPage() {
  return (
    <div className='search_page'>
        <div className='search_page_filter'>
            <TuneOutlined/>
            <h2> FILTER </h2>
        </div>
        <hr/>

        <ChannelRow
            image="https://i.pinimg.com/originals/8d/a5/ef/8da5ef64c8afee983fb042cee9efd434.jpg"
            channel="Sabina Sinkhu"
            verified
            subs="80K"
            no_of_videos={101}
            description="jadi di sini adalah kegabutan saya mengupload video ini"
        />

        <VideoRow
        views="10K"
        subs='80K'
        description='anda ingin cepat kaya, mari kerja bersama kami'
        timestamp='a year ago' 
        channel='Sabina Sinkhu' 
        title='YOLOOOO'
        image='https://cdn.eprnews.com/wp-content/uploads/2020/11/signs-to-be-rich-768x384.jpg'
        />

        <VideoRow
        views="5K"
        subs='80K'
        description='berolahraga supaya sehat'
        timestamp='59 seconds ago' 
        channel='Sabina Sinkhu' 
        title='HIYAAAAHH'
        image='https://mcs.com.pr/en/PublishingImages/Pages/Wellnes/Steps-to-Wellness/Ejercicio/Exercises.jpg'
        />

        <VideoRow
        views="5K"
        subs='80K'
        description='berolahraga supaya sehat'
        timestamp='9 days ago' 
        channel='Sabina Sinkhu' 
        title='LEBAARR'
        image='https://images.pexels.com/photos/1080722/pexels-photo-1080722.jpeg?cs=srgb&dl=agriculture-beautiful-view-city-park-1080722.jpg&fm=jpg'
        />
    </div>
  )
}

export default SearchPage