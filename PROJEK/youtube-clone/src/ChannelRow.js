import { Avatar } from '@mui/material'
import React from 'react';
import './ChannelRow.css';
import {VerifiedSharp } from '@mui/icons-material';

function ChannelRow({image, channel, subs, verified, no_of_videos, description}) {
  return (
    <div className='channel_row'>
        <Avatar className='channel_row_logo'
            alt={channel} src={image} />
        <div className='channel_row_text'>
            <h4> 
                {channel} {verified && <VerifiedSharp/>} 
            </h4>
            <p>
                {subs} subscribers • {no_of_videos} videos
            </p>
            <p>
                {description}
            </p>
        </div>
    </div>
  )
}

export default ChannelRow