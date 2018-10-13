import React, { Component } from 'react';
import styled from 'styled-components';
import { connect } from 'react-redux'
import { brewBeverage } from '../actions/beverage';

const BeverageWrapper = styled.div`
    display: flex;
    height: 250px;
    background: #d8d8d8;
    font-size: 40px;
    font-weight: bold;
    justify-content: center;
    align-items: center;
    cursor: pointer;
    padding: 32px;
    text-align: center;
    user-select: none;
    ${props => props.imageUrl && `
        background-image: url(${props.imageUrl});
        background-size: cover;
    `}
    color: white;
    text-shadow: 0px 1px 8px #000000;
`;

class Beverage extends Component {
    handleClick = () => this.props.onClick();

    render() {
        const { imageUrl, title } = this.props;
        return (
            <BeverageWrapper imageUrl={imageUrl} onClick={this.handleClick}>
                {title}
            </BeverageWrapper>
        );
    }
}

export default connect(
    undefined,
    (dispatch, { id }) => ({
        onClick: () => dispatch(brewBeverage(id)),
    })
)(Beverage);
